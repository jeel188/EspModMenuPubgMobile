//
// Create by Putri on 30/05/2021
//
#ifndef JEEL_PATEL_MEMORY_H
#define JEEL_PATEL_MEMORY_H

#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Process.h"

using namespace std;

typedef unsigned int kaddr;

// Unsigned base types.
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

// Signed base types.
typedef signed char int8;
typedef signed short int int16;
typedef signed int int32;
typedef signed long long int64;

// Character types.
typedef char ANSICHAR;
typedef wchar_t WIDECHAR;
typedef uint8 CHAR8;
typedef uint16 CHAR16;
typedef uint32 CHAR32;
typedef WIDECHAR TCHAR;

static kaddr libbase = 0;


pid_t find_pid(const char *process_name)
{
	int id;
	pid_t pid = -1;
	DIR *dir;
	FILE *fp;
	char filename[128];
	char cmdline[256];

	struct dirent *entry;
	if (process_name == NULL)
	{
		return -1;
	}
	dir = opendir("/proc");
	if (dir == NULL)
	{
		return -1;
	}
	while ((entry = readdir(dir)) != NULL)
	{

		sscanf(entry->d_name, "%d", &id);

		// id = atoi(entry->d_name);

		if (id != 0)
		{
			sprintf(filename, "/proc/%d/cmdline", id);
			fp = fopen(filename, "r");
			if (fp)
			{
				fgets(cmdline, sizeof(cmdline), fp);
				fclose(fp);

				if (strcmp(process_name, cmdline) == 0)
				{
					/* process found */
					pid = id;
					break;
				}
			}
		}
	}

	closedir(dir);
	return pid;
}

int isapkrunning(const char *bm)
{
	DIR *dir = NULL;
	struct dirent *ptr = NULL;
	FILE *fp = NULL;
	char filepath[50];			// 大小随意，能装下cmdline文件的路径即可
	char filetext[128];			// 大小随意，能装下要识别的命令行文本即可
	dir = opendir("/proc/");	// 打开路径
	if (dir != NULL)
	{
		while ((ptr = readdir(dir)) != NULL)	// 循环读取路径下的每一个文件/文件夹
		{
			// 如果读取到的是"."或者".."则跳过，读取到的不是文件夹名字也跳过
			if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
				continue;
			if (ptr->d_type != DT_DIR)
				continue;
			sprintf(filepath, "/proc/%s/cmdline", ptr->d_name);	// 生成要读取的文件的路径
			fp = fopen(filepath, "r");	// 打开文件
			if (NULL != fp)
			{
				fgets(filetext, sizeof(filetext), fp);	// 读取文件
				if (strcmp(filetext, bm) == 0)
				{
					closedir(dir);
					return 1;
				}
				fclose(fp);
			}
		}
	}
	closedir(dir);				// 关闭路径
	return 0;
}
bool VMRead(void* address, void* buffer, size_t size) {
    struct iovec local[1];
    struct iovec remote[1];
    local[0].iov_base = buffer;
    local[0].iov_len = size;
    remote[0].iov_base = address;
    remote[0].iov_len = size;
    ssize_t bytes = syscall(process_vm_readv_syscall, target_pid, local, 1, remote, 1, 0);
    return bytes == size;
}
int ReadTM(kaddr addr)
{
	int *data = (int *)malloc(4);
	vm_readv(reinterpret_cast < void *>(addr), data, 4);

	int paddr = *(int *)data;
	return paddr;
	free(data);
}


#define SIZE sizeof(kaddr)

kaddr getRealOffset(kaddr offset)
{
	if (libbase == 0)
	{
		puts("\nError: Can't Find Base Addr for Real Offset");
		return 0;
	}
	return (libbase + offset);
}

template < typename T > T Read(kaddr address)
{
	T data;
	vm_readv(reinterpret_cast < void *>(address), reinterpret_cast < void *>(&data), sizeof(T));
	return data;
}

template < typename T > void Write(kaddr address, T data)
{
	vm_writev(reinterpret_cast < void *>(address), reinterpret_cast < void *>(&data), sizeof(T));
}

template < typename T > T * ReadArr(kaddr address, unsigned int size)
{
	T data[size];
	T *ptr = data;
	vm_readv(reinterpret_cast < void *>(address), reinterpret_cast < void *>(ptr),
			 (sizeof(T) * size));
	return ptr;
}

char *ReadStr(kaddr address, unsigned int size)
{
	char *data = new char[size];
	for (int i = 0; i < size; i++)
	{
		vm_readv(reinterpret_cast < void *>(address + (sizeof(char) * i)),
				 reinterpret_cast < void *>(data + i), sizeof(char));
		if (data[i] == '\0')
		{
			break;
		}
	}
	return data;
	delete data;
}
int getINT (uintptr_t address){
    int tmp;
    VMRead((void *)address, &tmp, sizeof(tmp));
    return tmp;
}
#define SIZE sizeof(kaddr)
int isValid32(kaddr addr)
{
	if (addr < 0x10000000 || addr > 0xefffffff || addr % SIZE != 0)
		return 0;
	return 1;
}

kaddr getPtr(kaddr address)
{
	return Read < kaddr > (address);
}

#endif // JEEL_PATEL_MEMORY_H
