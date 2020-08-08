
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll convertHalf(vector<char>& nums, int begin, int end, int target)
{
	ll result = 0;

	for(int i = begin; i < end; i++)
	{
		if(nums[i] != target)
			result++;
	}
	// std::cout << "begin: " << begin << ", end: " << end << ", target: " << target << ", result: " << result << std::endl;
	return result;
}

ll Recurse(vector<char>& nums, int begin, int end, int target)
{
	if(end-begin == 1) return nums[begin] != target;

	ll result = 0;
	int halfWay = begin+(end-begin)/2;
	result = min(convertHalf(nums, begin, halfWay, target) + Recurse(nums, halfWay, end, target+1),
			 Recurse(nums, begin, halfWay, target+1) + convertHalf(nums, halfWay, end, target));

	return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
    	//n is a power of 2;
    	int n;
    	cin >> n;

    	vector<char> nums(n);
    	for(int i = 0; i < n; i++)
    		cin >> nums[i];

    	ll result = Recurse(nums, 0, n, 97);
    	std::cout << result << "\n";
    }

	return 0;
}