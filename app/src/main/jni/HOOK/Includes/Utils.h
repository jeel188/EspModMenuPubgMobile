#ifndef UTILS_H
#define UTILS_H

#include <jni.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef unsigned long DWORD1;
static uintptr_t libBase;

DWORD1 findLibrary(const char *library);

DWORD1 getAbsoluteAddress(const char *libraryName, DWORD1 relativeAddr);

bool isLibraryLoaded(const char *libraryName);

DWORD1 findLibrary(const char *library) {
    char filename[0xFF] = {0},
            buffer[1024] = {0};
    FILE *fp = NULL;
    DWORD1 address = 0;

    sprintf(filename, "/proc/self/maps");

    fp = fopen(filename, "rt");
    if (fp == NULL) {
        perror("fopen");
        goto done;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, library)) {
            address = (DWORD1) strtoul(buffer, NULL, 16);
            goto done;
        }
    }

    done:

    if (fp) {
        fclose(fp);
    }

    return address;
}

DWORD1 getAbsoluteAddress(const char *libraryName, DWORD1 relativeAddr) {
    libBase = findLibrary(libraryName);
    if (libBase == 0)
        return 0;
    return (reinterpret_cast<DWORD1>(libBase + relativeAddr));
}

bool isLibraryLoaded(const char *libraryName) {
    char line[512] = {0};
    FILE *fp = fopen("/proc/self/maps", "rt");
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, libraryName))
                return true;
        }
        fclose(fp);
    }
    return false;
}

#endif
