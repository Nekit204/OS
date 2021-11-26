#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;

DWORD pid = NULL;
DWORD WINAPI A();
DWORD WINAPI B();
CRITICAL_SECTION cs;



int main()
{
	pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	DWORD ChildId1 = NULL;
	DWORD ChildId2 = NULL;
	HANDLE hChild1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)A, NULL, 0, &ChildId1);
	HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)B, NULL, 0, &ChildId2);
	InitializeCriticalSection(&cs);
	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			EnterCriticalSection(&cs);
		}
		if (i == 60)
		{
			LeaveCriticalSection(&cs);
		}
		
		Sleep(100);
		printf("%d.MAIN\n", i);

		if (i == 60)
		{
			EnterCriticalSection(&cs);
			LeaveCriticalSection(&cs);
		}
				
	}
	WaitForSingleObject(hChild1, INFINITE);
	CloseHandle(hChild1);
	WaitForSingleObject(hChild2, INFINITE);
	CloseHandle(hChild2);
	DeleteCriticalSection(&cs);
}

DWORD WINAPI A()
{
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			EnterCriticalSection(&cs);
		}
		if (i == 60)
		{
			LeaveCriticalSection(&cs);
		}
		
		Sleep(100);
		printf("%d.A\n", i);

		if (i == 60)
		{
			EnterCriticalSection(&cs);
			LeaveCriticalSection(&cs);
		}
	}
	return 0;
}


DWORD WINAPI B()
{
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			EnterCriticalSection(&cs);
		}
		if (i == 60)
		{
			LeaveCriticalSection(&cs);
		}
		
		Sleep(100);
		printf("%d.B\n", i);

		if (i == 60)
		{
			EnterCriticalSection(&cs);
			LeaveCriticalSection(&cs);
		}
	
	}
	return 0;
}
