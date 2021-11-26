#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <locale>

void sayHeapInfo(HANDLE sh);


int main()
{
	HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4096, 0);
	std::cout << "--------------Whitout array--------------------\n";
	sayHeapInfo(heap);

	int* m = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 500 * sizeof(int));
	std::cout << "--------------Whith array--------------------\n";
	sayHeapInfo(heap);


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