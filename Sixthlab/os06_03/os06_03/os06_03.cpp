#include <iostream>
#include <Windows.h>

using namespace std;
#define PG (4096)
int pg = 256;

int main()
{
    setlocale(LC_ALL, "rus");

    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);

    int* virtArray = (int*)VirtualAlloc(NULL, pg * PG, MEM_COMMIT, PAGE_READWRITE);
    for (int i = 0; i < pg * PG / 4; i++)
    {
        virtArray[i] = i;
    }

    int index = ('З' * system_info.dwPageSize + (L'А' << 4) + (L'К' << 4)) / sizeof(int); //З=С7=199   А=С0=192     К=CA=202        C0C=3084
    cout << virtArray[index] << endl;

    cout << endl;
}

