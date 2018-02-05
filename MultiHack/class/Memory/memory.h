#ifndef MEMORY_H
#define MEMORY_H

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <QDebug>

class Memory{
public:
    Memory();
    bool attachProcess();
    DWORD read(DWORD address);
    void write(DWORD address, DWORD value);
    DWORD getModule(char* ModuleName);
    HWND hwnd;
private:
    DWORD processId;
    HANDLE hProcess;
    DWORD m_module = 0x0;


};

#endif // MEMORY_H
