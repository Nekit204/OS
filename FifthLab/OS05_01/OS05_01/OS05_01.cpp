#include <iostream>
#include <Windows.h>

void printProcessPrty(HANDLE h);
void printThreadPrty(HANDLE h);

using namespace std;
int main()
{
    try
    {
        HANDLE hp = GetCurrentProcess();
        HANDLE ht = GetCurrentThread();

        printProcessPrty(hp);
        printThreadPrty(ht);

      

        DWORD_PTR pa = NULL, sa = NULL;
        DWORD icpu = -1;
        if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "GetProcessAffinityMask";
        string bin{};
        int val = pa;
        int count = 0;
        while (val > 0)
        {
            if (val % 2 == 0)
            {
                bin.insert(bin.begin(), '0');
            }
            else
            {
                bin.insert(bin.begin(), '1');
                count++;
            }
            val >>= 1;
        }
        cout <<"Count of process for processor:"<< count << endl;
        cout << "Proccess Afinity Mask in 2 base: " << showbase << bin << endl;
        cout << "Process affinity Mask: " << showbase << hex << pa << "\n";
        cout << "System affinity Mask: " << showbase << hex << sa << "\n";
       icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);
        cout << "Thread Ideal Processor: " << dec << icpu << "\n";

        cout << "\n\n";


    }
    catch (char* msg) { cout << "Error: " << msg << "\n"; }

    system("pause");
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