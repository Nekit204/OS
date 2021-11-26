#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	HANDLE hm = OpenMutex(SYNCHRONIZE, FALSE, L"smwMutex");

	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			WaitForSingleObject(hm, INFINITE);
			while (i < 60)
			{
				Sleep(100);
				printf("%d.OS07_03B\n", i);
				i++;
			}
			ReleaseMutex(hm);
		}
		Sleep(100);
		printf("%d.OS07_03B\n", i);
	}
}