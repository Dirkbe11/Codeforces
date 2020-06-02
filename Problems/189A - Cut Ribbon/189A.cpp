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


/*===================
BOTTOM-UP
 ===================*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    std::vector<int> vals(4, 0);
    int n;
    cin >> n >> vals[1] >> vals[2] >> vals[3];
    
    std::vector<ll> dp(n+1, INT_MIN);
    dp[0] = 0;
    
    for(int i = 1; i <= 3; i++)
    {
	for(int j = vals[i]; j <= n; j++)
	{
	    dp[j] = max(dp[j], dp[j-vals[i]] + 1);
	}
    }

    ll result = (dp[n] == INT_MIN) ? 1 : dp[n];
    std::cout << result << "\n";
    
}





/*===================
TOP-DOWN
 ===================*/
//std::unordered_map<int, int> memo;

// ll TopDown(int n, int index, int a, int b, int c)
// {
//     if(index == n) return 0;
//     if(n-index < min({a, b, c}) || index > n) return INT_MIN;
    
//     if(memo.find(index) != memo.end()) return memo[index];

//     ll result = INT_MIN;
//     if(n-index >= a)
// 	result = max(result, TopDown(n, index+a, a, b, c) + 1);
//     if(n-index >= b)
// 	result = max(result, TopDown(n, index+b, a, b, c) + 1);
//     if(n-index >= c)
// 	result = max(result, TopDown(n, index+c, a, b, c) + 1);
 
//     return memo[index] = result;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int n, a, b, c;
//     cin >> n >> a >> b >> c;

//     ll result = TopDown(n, 0, a, b, c);
//     ll minVal = 1;
//     result = max(minVal, result);
//     std::cout << result << "\n";
// }
