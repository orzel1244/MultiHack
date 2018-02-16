#ifndef MEMORY_H
#define MEMORY_H

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <QDebug>
#include <QMap>

class Memory{
public:
    Memory();
    bool attachProcess();
    int read(DWORD address);
    void write(DWORD dwAddress, DWORD value);
    void writeFloat(DWORD dwAddress, float value);
    DWORD getModule(char* ModuleName);
    HWND hwnd;
private:
    DWORD processId;
    HANDLE hProcess;
    QMap<QString, DWORD> cache;


};

#endif // MEMORY_H
