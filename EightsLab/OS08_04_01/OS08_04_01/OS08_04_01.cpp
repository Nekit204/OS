#include <iostream>
#include <ctime>
#include <Windows.h>
#include <tlhelp32.h>
#include <stdio.h>

using namespace std;

DWORD ChildThread();
int simple(int n);

bool stop = false;

int main() {
	clock_t start = clock();
	
	HANDLE htimer = OpenWaitableTimer(TIMER_ALL_ACCESS, FALSE, L"OS08_04");

	DWORD ChildId2 = NULL;
	HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, 0, &ChildId2);

	WaitForSingleObject(htimer, INFINITE);
	stop = true;
	CloseHandle(hChild2);

	cout << "time: " << clock() - start << endl;

	system("pause");
	return 0;
}


DWORD ChildThread() {
	DWORD tid = GetCurrentThreadId();

	for (long long i = 2; ; i++) {
		if (stop) {
			break;
		}

		if (simple(i)) {
			cout << i << endl;
		}
	}

	return 0;
}

int simple(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if ((n % i) == 0) {
			return 0;
		}
	}

	return 1;
}