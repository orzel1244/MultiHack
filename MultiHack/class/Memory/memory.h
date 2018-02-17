#ifndef MEMORY_H
#define MEMORY_H

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <QDebug>
#include <QThread>
#include <QMap>

class Memory{
public:
    Memory();
    bool attachProcess();
    int read(DWORD address);

    template <typename T>
    void write(DWORD dwAddress, T value){
        WriteProcessMemory(hProcess, (LPVOID)dwAddress, &value, sizeof(T), 0);
    }

//    void writeFloat(DWORD dwAddress, float value);
    DWORD getModule(char* ModuleName);
    HWND hwnd;
private:
    DWORD processId;
    HANDLE hProcess;
    QMap<QString, DWORD> cache;

};

#endif // MEMORY_H
