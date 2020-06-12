
#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

ll Sleeps[2001];


bool in(int x, int l, int r) {
	return l <= x && x <= r;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));

    for(int i = 0; i < n; i++)
    {
	cin >> Sleeps[i];
    }

    dp[0][0] = 0;
    ll TIME = 0;
    for(int i = 1; i <= n; i++)
    {
	TIME += Sleeps[i-1];
	for(int j = 0; j <= n; j++)
	{
	   if(j)
	   {
	       dp[i][j] = max(dp[i][j], dp[i-1][j-1] + in((TIME-j)%h, l, r));
	   }
	   
	   dp[i][j] = max(dp[i][j], dp[i-1][j] + in((TIME-j)%h, l, r));
	}
	
    }


    int result = 0;
    for(int i = 0; i <= n; i++)
    {
	result = max(result, dp[n][i]);
    }

    std::cout << result << "\n";
    
    
    return 0;
}
