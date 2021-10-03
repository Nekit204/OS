#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();

	for (int i = 0; i < 10000000; i++)
	{
		Sleep(1000);
		cout << "PID: " << pid << endl;
		cout << "TID:" << tid << endl;
	}
}