#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <TlHelp32.h>
#include <cwchar>
using namespace std;

int main()
{
	/*string str="";
	string findstr = "";
	string command = "tasklist";
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE);
	cout << "Do you want to find process?[y/n]";
	cin >> str;
	cout << endl;
	if (str == "y")
	{
		command += " /fi \" IMAGENAME eq ";
		cout << "Name of process: ";
		cin >> findstr;
		cout << endl;
		command += findstr;
		command += " \"";
		const char* c = command.c_str();
		system(c);
	}
	else if (str == "n")
	{
		const char* c = command.c_str();
		system(c);
	}
	else
	{
		cout << "Not found command!" << endl;
	}*/
	DWORD pid = GetCurrentProcessId();
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 peProcessEntry;
	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	wcout << L"Current PID = " << pid << endl << L"--------------------------------------" << endl;
	try
	{
		if (!Process32First(snap, &peProcessEntry)) throw L"Process32First";
		do
		{
			wcout << L"Name= " << peProcessEntry.szExeFile << endl
				<< L"PID= " << peProcessEntry.th32ProcessID
				<< L",Parent PID = " << peProcessEntry.th32ParentProcessID;
			if (peProcessEntry.th32ProcessID == pid) wcout << "--> current process";
			wcout << endl << L"-----------------------------------------------" << endl;
		} while (Process32Next(snap, &peProcessEntry));
	}
	catch (char* msg) { wcout << L"ERROR :" << msg << endl; }
	system("pause");
	return 0;
}

