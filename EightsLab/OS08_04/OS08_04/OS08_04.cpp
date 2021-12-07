#include <iostream>
#include <ctime>
#include <Windows.h>

#define SECOND 10000000

using namespace std;

int main() {
    clock_t start = clock();

    DWORD pid = GetCurrentProcessId();
    cout << "Main PID: " << pid << endl;

    long long it = -60 * SECOND;
    HANDLE htimer = CreateWaitableTimer(NULL, FALSE, L"OS08_04");
    if (!SetWaitableTimer(htimer, (LARGE_INTEGER*)&it, 60000, NULL, NULL, FALSE)) {
        throw "Error SrtWaitableTimer";
    }

    LPCWSTR an = L"D:\\study\\3course\\OS\\EightsLab\\OS08_04_01\\Debug\\OS08_04_01.exe";
    PROCESS_INFORMATION pi1, pi2;
    pi1.dwThreadId = 1;  pi2.dwThreadId = 2;

    {
        STARTUPINFO si; ZeroMemory(&si, sizeof(STARTUPINFO)); si.cb = sizeof(STARTUPINFO);
        CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1) ?
            cout << "Process OS08_04_01 created \n" : cout << "Process OS08_04_01 not created \n";
    }
    {
        STARTUPINFO si; ZeroMemory(&si, sizeof(STARTUPINFO)); si.cb = sizeof(STARTUPINFO);
        CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi2) ?
            cout << "Process OS08_04_01 created \n" : cout << "Process OS08_04_01 not created \n";
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CancelWaitableTimer(htimer);

    cout << "time: " << clock() - start << endl;

    system("pause");
    return 0;
}
