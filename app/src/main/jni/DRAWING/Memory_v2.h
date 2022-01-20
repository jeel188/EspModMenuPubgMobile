
#ifndef JEEL_PATEL_V2_MEMORY_H
#define JEEL_PATEL_V2_MEMORY_H

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

enum TYPE {
    TYPE_DWORD,
    TYPE_FLOAT
};

uintptr_t lib_base = 0;
int handle = 0;

bool initMemory();
pid_t getPid(const char *pkg_name);
int isApkRunning(const char *pkg_name);
uintptr_t getModuleAddress(int game_pid, const char *module_name);
void Write(uintptr_t address, const char *value, TYPE type);
void WriteDword(uintptr_t address, int value);
void WriteFloat(uintptr_t address, float value);
uintptr_t getRealOffset(uintptr_t address);
/*
uintptr_t getRealOffset(uintptr_t address)
{
    if (lib_base == 0)
        LOGE("Error: Can't get memory base address");
    return lib_base + address;
}*/

bool initMemory(){
    int game_pid = 0;
    bool isResult = false;
    if (isApkRunning("com.tencent.ig") == 1){
        game_pid = getPid("com.tencent.ig");
       // Offsets::globalOffsets();
        puts("PUBGM Global version is runnning");
    } else if (isApkRunning("com.vng.pubgmobile") == 1){
       // Offsets::vietnamOffsets();
        game_pid = getPid("com.vng.pubgmobile");
        puts("PUBGM Vietnam version is runnning");
    } else if (isApkRunning("com.pubg.krmobile") == 1){
        //Offsets::koreaOffsets();
        game_pid = getPid("com.pubg.krmobile");
        puts("PUBGM Korea version is runnning");
    } else if (isApkRunning("com.rekoo.pubgm") == 1){
       // Offsets::taiwanOffsets();
        game_pid = getPid("com.rekoo.pubgm");
        puts("PUBGM Taiwan version is runnning");
    } else{
        puts("Can't get game pid!");
        isResult = false;
    }
    if (game_pid != 0){
        puts("Found pid: %d");
        lib_base = getModuleAddress(game_pid, "libUE4.so");
        if (lib_base == 0){
            isResult = false;
        } else {
            puts("Found base: %x");
            char lj[64];
            sprintf(lj, "/proc/%d/mem", game_pid);
            handle = open(lj, O_RDWR);
            if (handle != 0){
                lseek(handle, 0, SEEK_SET);
                isResult = true;
            }
        }
    }
    return isResult;
}

int isApkRunning(const char *pkg_name){
    if (getPid(pkg_name) != 0 && getPid(pkg_name) > 0){
        return 1;
    }
    return 0;
}


pid_t getPid(const char *pkg_name){
    pid_t pid = 0;
    int id;
    DIR* dir;
    FILE* fp;
    char filename[32];
    char cmdline[256];

    struct dirent* entry;
    if (pkg_name == NULL) {
        return -1;
    }
    dir = opendir("/proc");
    if (dir == NULL) {
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        id = atoi(entry->d_name);
        if (id != 0) {
            sprintf(filename, "/proc/%d/cmdline", id);
            fp = fopen(filename, "r");
            if (fp) {
                fgets(cmdline, sizeof(cmdline), fp);
                fclose(fp);
                if (strcmp(pkg_name, cmdline) == 0) {
                    pid = id;
                    break;
                }
            }
        }
    }
    closedir(dir);
    return pid;
}

uintptr_t getModuleAddress(int game_pid, const char *module_name){
    FILE *fp;
    unsigned int addr = 0;
    char filename[32], buffer[1024];
    snprintf(filename, sizeof(filename), "/proc/%d/maps", game_pid);
    fp = fopen(filename, "rt");
    if (fp != nullptr) {
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strstr(buffer, module_name)) {
                addr = (uintptr_t)strtoull(buffer, NULL, 16);
                break;
            }
        }
        fclose(fp);
    }
    return addr;
}

void Write(uintptr_t address, const char *value, TYPE type){
    switch (type) {
        case TYPE_DWORD:
            WriteDword(address, atoi(value));
            break;
        case TYPE_FLOAT:
            WriteFloat(address, atof(value));
            break;
    }
}

void WriteDword(uintptr_t address, int value) {
    pwrite64(handle, (void*)&value, sizeof(value), address);
}

void WriteFloat(uintptr_t address, float value) {
    pwrite64(handle, (void*)&value, sizeof(value), address);
}




#endif //JEEL_PATEL_V2_MEMORY_H
