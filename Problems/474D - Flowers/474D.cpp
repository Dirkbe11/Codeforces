
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
constexpr const int MOD = 1e9 + 7;

ll dp[100001][2];
ll summation[100001];
//dp[i][0] => flower i is red
//dp[i][1] => flower i is white
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, k;
    cin >> t >> k;
    int previousLastIndex = 0;

    	dp[0][0] = 1;
	dp[k][1] = 1;
	summation[0] = 0;
	
	for(int i = 1; i <= 100000; i++)
	{
	    dp[i][0] = (dp[i][0] + dp[i-1][0] + dp[i-1][1])%MOD;

	    if(i - k > 0)
	    {
		dp[i][1] = (dp[i-k][1] + dp[i-k][0]) % MOD;
	    }
	    summation[i] = (dp[i][0] + dp[i][1] + summation[i-1])%MOD;
	}
	
    
    while(t--)
    {
	int a, b;
	cin >> a >> b;
	
	ll result = (((summation[b] - summation[a-1]) % MOD)+MOD) % MOD;

	std::cout << result << "\n";
	
    }
    return 0;
}
