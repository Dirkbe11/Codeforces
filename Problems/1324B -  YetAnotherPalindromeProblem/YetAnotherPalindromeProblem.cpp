#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
	int testCases = 0;
	std::cin >> testCases;
	
	while(testCases--)
	{
		int vecLength = 0;
		std::cin >> vecLength;
		if(vecLength < 3)
		{
			std::cout << "NO" << "\n";
			continue;
		}

		std::unordered_map<int, pair<int, int>> mapped;
		int index = 0;
		int value = 0;
		
		while(vecLength--)
		{
			std::cin >> value;
			if(mapped.find(value) == mapped.end())
				mapped[value] = {index, 0};
			else
				mapped[value].second = index;
			
			index++;
		}

		bool flag = false;
		for(auto it : mapped)
		{
			if((it.second.second - it.second.first)+1 >= 3)
			{
				std::cout << "YES" << "\n";
				flag = true;
				break;
			}
		}
		if(!flag)
			std::cout << "NO" << "\n";
	}	
}
