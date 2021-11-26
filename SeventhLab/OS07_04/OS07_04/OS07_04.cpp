#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	LPCWSTR an1 = L"D:\\study\\3course\\OS\\SeventhLab\\OS07_04A\\DEBUG\\OS07_04A.exe";
	LPCWSTR an2 = L"D:\\study\\3course\\OS\\SeventhLab\\OS07_04B\\DEBUG\\OS07_04B.exe";
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	ZeroMemory(&si1, sizeof(STARTUPINFO)); si1.cb = sizeof(STARTUPINFO);
	ZeroMemory(&si2, sizeof(STARTUPINFO)); si2.cb = sizeof(STARTUPINFO);

	HANDLE hs = CreateSemaphore(NULL, 2,2, L"smwSem");

	if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
		cout << "Process OS07_04A.exe created!" << endl;
	else
		cout << "Process OS07_04A.exe not created!" << endl;

	if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
		cout << "Process OS07_04B.exe created!" << endl;
	else
		cout << "Process OS07_04B.exe not created!" << endl;

	DWORD pid = GetCurrentProcessId();
	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			WaitForSingleObject(hs, INFINITE);
			while (i < 60)
			{
				Sleep(100);
				printf("%d.MAIN\n", i);
				i++;
			}
			LONG prevcount = 0;
			ReleaseSemaphore(hs,1,&prevcount);
		}
		Sleep(100);
		printf("%d.MAIN\n", i);
	}
	WaitForSingleObject(pi1.hProcess, INFINITE);
	CloseHandle(pi1.hProcess);
	WaitForSingleObject(pi2.hProcess, INFINITE);
	CloseHandle(pi2.hProcess);
}