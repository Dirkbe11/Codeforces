
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin>> testcases;
    while(testcases--)
    {
	int n;
	cin >> n;

        vector<ll> nums(32, 0);
	ll result = 0;
	for(int i = 0; i < n; i++)
	{
	    int val;
	    cin >> val;

	    ll count = 0;
	    while(val)
	    {
		count++;
		val /= 2;
	    }

	    result += nums[count];
	    nums[count]++;
	    
	}

	std::cout << result << "\n";

	
    }
    return 0;
}
