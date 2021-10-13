#include <Windows.h>
#include <iostream>

void printProcessPrty(HANDLE h);
void printThreadPrty(HANDLE h);

using namespace std;
int main()
{
    HANDLE hp = GetCurrentProcess();
    HANDLE ht = GetCurrentThread();
    setlocale(LC_ALL, "Russian");
    DWORD icpu = -1;
    for (int i = 1; i <= 1000000; i++)
    {
        if (i % 1000 == 0)
        {
            Sleep(500);
            cout << "Номер итерации:  " << i << endl;
            cout << "PID: " << GetCurrentProcessId() << endl;
            cout << "TID: " << GetCurrentThreadId() << endl;
            printProcessPrty(hp);
            printThreadPrty(ht);
            icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);
            cout << "Thread Ideal Processor: " << dec << icpu << "\n";
        }
    }
}

void printProcessPrty(HANDLE h)
{
    DWORD prty = GetPriorityClass(h);
    cout << "----- Current PID = " << GetCurrentProcessId() << " \n";
    switch (prty)
    {
    case IDLE_PRIORITY_CLASS:   cout << "----+ priority = IDLE_PRIORITY_CLASS \n";  break;
    case BELOW_NORMAL_PRIORITY_CLASS:   cout << "----+ priority = ELOW_NORMAL_PRIORITY_CLASS \n";  break;
    case NORMAL_PRIORITY_CLASS:   cout << "----+ priority = NORMAL_PRIORITY_CLASS \n";  break;
    case ABOVE_NORMAL_PRIORITY_CLASS:   cout << "----+ priority = ABOVE_NORMAL_PRIORITY_CLASS \n";  break;
    case HIGH_PRIORITY_CLASS:   cout << "----+ priority = HIGH_PRIORITY_CLASS \n";  break;
    case REALTIME_PRIORITY_CLASS:   cout << "----+ priority = REALTIME_PRIORITY_CLASS \n";  break;
    default:       cout << "----+ priority = ? \n";    break;
    }

}

void printThreadPrty(HANDLE h)
{
    int prty = GetThreadPriority(h);
    cout << "----- Current TID = " << GetCurrentThreadId() << " \n";
    switch (prty)
    {
    case THREAD_PRIORITY_LOWEST:   cout << "----+ priority = THREAD_PRIORITY_LOWEST \n";  break;
    case THREAD_PRIORITY_BELOW_NORMAL:   cout << "----+ priority = THREAD_PRIORITY_BELOW_NORMAL \n";  break;
    case THREAD_PRIORITY_NORMAL:   cout << "----+ priority = THREAD_PRIORITY_NORMAL \n";  break;
    case THREAD_PRIORITY_ABOVE_NORMAL:   cout << "----+ priority = THREAD_PRIORITY_ABOVE_NORMAL \n";  break;
    case THREAD_PRIORITY_HIGHEST:   cout << "----+ priority = THREAD_PRIORITY_HIGHEST \n";  break;
    case THREAD_PRIORITY_IDLE:   cout << "----+ priority = THREAD_PRIORITY_IDLE \n";  break;
    case THREAD_PRIORITY_TIME_CRITICAL:   cout << "----+ priority = THREAD_PRIORITY_TIME_CRITICAL \n";  break;
    default:       cout << "----+ priority = ? \n";    break;
    }

}
