#include "memory.h"

Memory::Memory(){
    attachProcess();
}

bool Memory::attachProcess(){
    //    if(hwnd == INVALID_HANDLE_VALUE){
    hwnd = FindWindow(NULL,L"Counter-Strike: Global Offensive");
    GetWindowThreadProcessId(hwnd,&processId);
    hProcess = OpenProcess(PROCESS_VM_READ |
                           PROCESS_QUERY_INFORMATION |
                           PROCESS_VM_WRITE |
                           PROCESS_VM_OPERATION, false, processId);
    //    }
}

DWORD Memory::getModule(char *ModuleName){
    if(cache.contains(ModuleName)){
        return cache.value(ModuleName);
    }
    HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);
    MODULEENTRY32 mEntry;
    if (hModule == INVALID_HANDLE_VALUE) {
        return 0;
    }
    mEntry.dwSize = sizeof(mEntry);

    const WCHAR *modNameChar;
    int nChars = MultiByteToWideChar(CP_ACP, 0, ModuleName, -1, NULL, 0);
    modNameChar = new WCHAR[nChars];
    MultiByteToWideChar(CP_ACP, 0, ModuleName, -1, (LPWSTR)modNameChar, nChars);

    do
        if (!wcscmp(mEntry.szModule, modNameChar)) {
            CloseHandle(hModule);
            cache.insert(ModuleName, (DWORD)mEntry.modBaseAddr);
            return (DWORD)mEntry.modBaseAddr;
        }
    while (Module32Next(hModule, &mEntry));

    CloseHandle(hModule);
    return 0;
}

int Memory::read(DWORD address){
    DWORD value;
    ReadProcessMemory(hProcess, (LPVOID)address, &value,sizeof(DWORD),0);
    return value;
}
