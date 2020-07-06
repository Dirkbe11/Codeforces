
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



bool check(int mid, int eo, vector<int>& nums, int k)
{
    int ans = 0;

    for(int i = 0; i < nums.size(); i++)
    {
	if(!eo)
	{
	    ans++;
	    eo ^= 1;
	}
	else
	{
	    if(nums[i] <= mid)
	    {
		ans++;
		eo ^= 1;
	    }
	    
	}
    }

	return ans >= k;
}

int Solve(int n, int k, vector<int>& nums)
{
    int low = 0;
    int hi = 1e9;

    while(low < hi)
    {
	int mid = (low+hi)/2;
	if(check(mid, 0, nums, k) || check(mid, 1, nums, k))
	    hi = mid;
	else
	    low = mid+1;
    }

    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n  >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i < nums.size(); i++)
	cin >> nums[i];


    std::cout << Solve(n, k, nums) << "\n";


    return 0;
}
