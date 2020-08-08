
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
    	int n, k, z;
    	cin >> n >> k >> z;

    	vector<int> nums(n, 0);
    	for(int i = 0; i < n; i++)
    		cin >> nums[i];

    	int ans = 0;
    	int sum = 0;
    	int mx = 0;

    	for(int i = 0; i <= k; i++)
    	{
    		if(i < n-1)
    			mx = max(mx, nums[i] + nums[i+1]);

    		sum += nums[i];
    		if(i % 2 == k % 2) //this is to make sure we get an even #, odd-odd = even, even-even = even
    		{
    			int tmp = (k-i)/2;
    			if(tmp <= z)
    				ans = max(ans, sum+(mx*tmp));
 
    		}
    	}

    	std::cout << ans << "\n";

    	
    }

	return 0;
}