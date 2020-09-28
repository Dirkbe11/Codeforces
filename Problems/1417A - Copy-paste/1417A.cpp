
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
	int n, k;
	cin >> n >> k;

	int minV = INT_MAX;
        ll result = 0;

	for(int i = 0; i < n; i++)
	{
	    cin >> dp[i];
	    minV = min(minV, dp[i]);

	    if(dp[i] > k)
	    {
		std::cout << "0\n";
		goto finisher;
	    }
	}

	for(int i = 0; i < n; i++)
	{
	    result += (k-dp[i])/minV;
	}

	result -= (k-minV)/minV;


	std::cout << result << "\n";

    finisher:
	continue;
    }


    
	return 0;
}
