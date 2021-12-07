#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

int main()
{
	int count = 0;

	clock_t start_time = clock();
	bool is_five = false, is_ten = false;
	while (double((clock() - start_time) / CLOCKS_PER_SEC) < 15)
	{
		if (!is_five && double((clock() - start_time) / CLOCKS_PER_SEC) == 5)
		{
			cout << "After 5 second: " << count << endl;
			is_five = true;
		}

		if (!is_ten && double((clock() - start_time) / CLOCKS_PER_SEC) == 10)
		{
			cout << "After 10 second: " << count << endl;
			is_ten = true;
		}
		count++;
	}

	cout << "End count: " << count;
}
