
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

    	std::vector<int> nums(n);
    	for(int i = 0; i < n; i++)
    		cin >> nums[i];

    	//count how many times it switches directions

    	//should either be:
    	//-><- OR -> OR <-
    	//find:
    		//longest increasing from back to front
    		//longest decreasing from above interval to switch
    	
    	int decreasingIndex = n-1;

    	while(decreasingIndex && nums[decreasingIndex] <= nums[decreasingIndex-1])
    		decreasingIndex--;

    	int increasingIndex = decreasingIndex;

    	while(increasingIndex && nums[increasingIndex] >= nums[increasingIndex-1])
    		increasingIndex--;


    	std::cout << increasingIndex << "\n";

    }

	return 0;
}