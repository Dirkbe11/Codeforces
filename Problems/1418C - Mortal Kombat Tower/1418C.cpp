
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

	if(n == 0)
	{
	    std::cout << "0\n";
	    continue;
	}
	
	vector<vector<vector<ll>>> dp(n+2, vector<vector<ll>>(2, vector<ll>(2, INT_MAX)));

	dp[0][0][0] = dp[0][0][1] = 0;
	dp[0][1][0] = dp[0][1][1] = 0;
	dp[1][0][0] = dp[1][0][1] = 0;
	dp[1][1][0] = dp[1][1][1] = 0;

	//dp[i][j][k] = monster i, person j, k kills this round

	ll result = INT_MAX;
	for(int i = 0; i < n; i++)
	{
	    int monster;
	    cin >> monster;
	    
	    int index = i + 2;

	    for(int j = 0; j < 2; j++)
	    {
		if(j == 1 && !i) continue;
		
		int adder = (j == 0  && monster == 1) ? 1 : 0;

	      
		dp[index][j][0] = min({dp[index][j][0],
			               dp[index-1][!j][0] + adder,
			               dp[index-1][!j][1] + adder});

		dp[index][j][1] = min({dp[index][j][1],
			               dp[index-1][j][0] + adder});

	        if(i == n-1)
		    result = min({result, dp[index][j][0], dp[index][j][1]});
	    }

	    
	}

	std::cout << result << "\n";
	
    }
    
    return 0;
}
