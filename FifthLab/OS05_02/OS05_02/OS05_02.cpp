#include <Windows.h>
#include <iostream>
//#include <cassert>
//#include <sstream>

using namespace std;
void CreateProccersWithPriority(LPCWSTR an, STARTUPINFO si, int priority)
{
    PROCESS_INFORMATION pi;
    try {
        switch (priority)
        {
        case 1:CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | IDLE_PRIORITY_CLASS, NULL, NULL, &si, &pi); break;
        case 2:CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi); break;
        case 3:CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi); break;
        case 4:CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | ABOVE_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi); break;
        case 5:CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | BELOW_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi); break;
        case 6:CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | REALTIME_PRIORITY_CLASS, NULL, NULL, &si, &pi); break;
        }
    }
    catch(int)
    {
        cout << "Oops...Something wrong";
    }
  
}

int main(int argc, char* argv[])
{
    
    for (int i = 0; i < argc; i++)
    {
        cout << "arg" << i << ": " << argv[i] << "\n";
    }

    HANDLE hp = GetCurrentProcess();
    try
    {
        {
            DWORD pa = NULL, sa = NULL, icpu = -1;
            if (argv[1] != NULL)
            {
                unsigned long long mask;
                sscanf_s(argv[1], "%d", &mask);
                if (!SetProcessAffinityMask(hp, mask)) throw "SetProcessAffinityMask";

                if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "GetProcessAffinityMask";
                cout << " Process Affinity Mask: " << showbase << hex << pa << "\n";
                cout << " System Affinity Mask: " << showbase << hex << sa << "\n";
                cout << dec << noshowbase;

                if (argv[2] != NULL)
                {
                    STARTUPINFO si;
                    ZeroMemory(&si, sizeof(STARTUPINFO));
                    si.cb = sizeof(STARTUPINFO);

                    unsigned long long priority;
                    sscanf_s(argv[2], "%d", &priority);
                    CreateProccersWithPriority(L"D:\\study\\3course\\OS\\FifthLab\\OS05_02x\\Debug\\OS05_02x.exe", si, priority);


                    if (argv[3] != NULL)
                    {
                        sscanf_s(argv[3], "%d", &priority);
                        ZeroMemory(&si, sizeof(STARTUPINFO));
                        si.cb = sizeof(STARTUPINFO);
                        CreateProccersWithPriority(L"D:\\study\\3course\\OS\\FifthLab\\OS05_02x\\Debug\\OS05_02x.exe", si, priority);
                    }

                }
            }

        }
    }
    catch (char* msg) { std::cout << "Error " << msg << "\n"; }
}