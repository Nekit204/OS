#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	DWORD pid = GetCurrentProcessId();
	for (int i = 0; i < 125; i++)
	{
		Sleep(1000);
		cout << "PID: " << pid << endl;
	}
}
