#include <iostream>
#include <vector>

int main()
{
	int testCount;
	std::cin >> testCount;

	while(testCount--)
	{ 
		int testSize;
		std::cin >> testSize;

		std::vector<int> odd;
		std::vector<int> even;

		int input;
		for(int i = 1; i <= testSize; i++)
		{
			std::cin >> input;
			if(input & 1) odd.push_back(i);
			else		  even.push_back(i);
		}

		if(even.size())
		{
			std::cout << "1\n";
			std::cout << even[0] << "\n";
			continue;
		}
		if(odd.size() > 1)
		{
			std::cout << "2\n";
			std::cout << odd[0] << " " << odd[1] << "\n";
			continue;
		}

		std::cout << "-1\n";
	}
}