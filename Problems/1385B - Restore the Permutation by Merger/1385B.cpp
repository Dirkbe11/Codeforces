
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
    	int n;
    	cin >> n;

    	std::vector<int> nums(2*n, 0);

    	std::unordered_map<int, int> counter;

    	for(int i = 0; i < 2*n; i++)
    	{
    		cin >> nums[i];
    		counter[nums[i]]++;
    	}

    	std::unordered_map<int, int> counter2;

    	for(auto num : nums)
    	{
    		if(counter2[num] < counter[num]/2)
    		{
    			std::cout << num << " ";
    			counter2[num]++;
    		}
    	}

    	std::cout << "\n";
    }

	return 0;
}