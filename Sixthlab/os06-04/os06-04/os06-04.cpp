#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <locale>

void sayHeapInfo(HANDLE sh);


int main()
{
	HANDLE pheap = GetProcessHeap();
	std::cout << "--------------Whitout array--------------------\n";
	sayHeapInfo(pheap);

	{
		int size = 300000;
		int* m = new int[size];
		std::cout << "--- m = " << std::hex << m << "\n";
	}
	std::cout << "--------------Whith array--------------------\n";
	sayHeapInfo(pheap);

}


void sayHeapInfo(HANDLE sh)
{
	PROCESS_HEAP_ENTRY phe;
	phe.lpData = NULL;
	while (HeapWalk(sh, &phe))
	{
		std::cout << "--  address = " << std::hex << phe.lpData
			<< ", size = " << std::dec << phe.cbData
			<< ((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "")
			<< ((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "")
			<< ((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "")
			<< "\n";
	}
	std::cout << "----------------------------------------------------\n\n";
}