
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false)
typedef long long      ll;

int dp[5000][5000][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> colors(n);
    //initialize our DP matrix
    for(int i = 0; i < n; i++)
    {
	cin >> colors[i];
	//initialize our our colors array
	//while we are also filling out the DP matrix
	for(int j= 0; j < n; j++)
	{
	    dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : INT_MAX);
	}
    }
	
    for(int r = 0; r < n; r++)
    {
	for(int l = r; l >= 0; l--)
	{
	    for(int i = 0; i < 2; i++)
	    {
		int color = (i == 0 ? colors[l] : colors[r]);

		if(l)//determine min value if we changed
		    dp[l-1][r][0] = min(dp[l-1][r][0], dp[l][r][i] + (color != colors[l-1]));

		if(r + 1 < n)
		    dp[l][r+1][1] = min(dp[l][r+1][1], dp[l][r][i] + (color != colors[r+1]));
	    }
	}
    }

    std::cout << min(dp[0][n-1][1], dp[0][n-1][0]) << "\n";

    return 0;
}
