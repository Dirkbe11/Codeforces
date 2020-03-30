#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
	int testCases = 0;
	std::cin >> testCases;

	while(testCases--)
	{
		unordered_set<int> setted;
		int vals = 0;
		std::cin >> vals;

		int newValue = 0;
		for(int i = 0; i < vals; i++)
		{
			std::cin >> newValue;
			setted.insert(newValue);
		}

		std::cout << setted.size() << "\n";
	}
}