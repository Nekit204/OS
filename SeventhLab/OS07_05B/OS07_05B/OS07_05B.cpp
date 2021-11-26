#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	HANDLE he = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"smwEvent");

	WaitForSingleObject(he, INFINITE);
	for (int i = 0; i < 90; i++)
	{
		SetEvent(he);
		Sleep(100);
		printf("%d.OS07_05B\n", i);
	}
	CloseHandle(he);
}