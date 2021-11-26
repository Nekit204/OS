#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	HANDLE hs = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"smwSem");

	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			WaitForSingleObject(hs, INFINITE);
			while (i < 60)
			{
				Sleep(100);
				printf("%d.OS07_04B\n", i);
				i++;
			}
			LONG prevcount = 0;
			ReleaseSemaphore(hs, 1, &prevcount);
		}
		Sleep(100);
		printf("%d.OS07_04B\n", i);
	}
}