
#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define fastio ios::sync_with_stdio(false)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

//dp[i][j] = day i, what we did the previous day
int states[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    states[0] = 0;
    int dp[101][3];
    for(int i = 0; i <= n; i++)
    {
	if(i)
	    cin >> states[i];
	for(int j = 0; j < 3; j++)
	    dp[i][j] = 0;
    }


    int previousMax = 0;
    for(int i = 1; i <= n; i++)
    {
	dp[i][0] = previousMax;
	
	// if(states[i] == 0)
	// {
	//     dp[i][0]++;
	// }
	// else 
	    if(states[i] == 1)
	{
	    dp[i][1] = max(dp[i-1][0]+1, dp[i-1][2]+1);
	}
	else if(states[i] == 2)
	{
	    dp[i][2] = max(dp[i-1][0]+1, dp[i-1][1]+1);
	}
	else if(states[i] == 3)
	{
	     dp[i][1] = max(dp[i-1][0]+1, dp[i-1][2]+1);
	     dp[i][2] = max(dp[i-1][0]+1, dp[i-1][1]+1);
	}

	previousMax = max({dp[i][0], dp[i][1], dp[i][2]});
    }

    int result = max({dp[n][0], dp[n][1], dp[n][2]});
    std::cout << n-result << "\n";
    
    
    return 0;
}
