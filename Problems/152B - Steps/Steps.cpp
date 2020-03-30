/**
    __author__ : Kodex
    problems_ID:
*/

#include <bits/stdc++.h>
using namespace std;
// #define mp             make_pair
// #define pb             push_back
// #define fi             first
// #define se             second
// #define sz(x)          (int)((x).size())
// #define fill(x, y)     memset(x, y, sizeof(y))
// #define all(x)         (x).begin(), (x).end()
// #define sci(x)         int x;       scanf("%d", &x);
// #define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
// #define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
// #define TC(x)          sci(x); while(x --)
// #define eprintf(...)   fprintf(stderr, __VA_ARGS__)
// #define debug(x)       { cerr << #x << " = " << x << endl; }
// #define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
// #define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
// #define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
// #define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
// typedef pair<int, int> ii;
// typedef pair<ii, int>  iii;
// typedef vector<int>    vi;
// typedef vector<ii>     vii;
// typedef vector<iii>    viii;
// const   int            inf = 0;
// const   double         eps = 0;
// const   int            ms  = 0;
// const   int            md  = 0;


bool valid(ll x, ll y, ll n, ll m)
{
	return (x > 0 && y > 0 && x<= n && y <=m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    ll x,y, k;
    cin >> x >> y >> k;

    ll answer = 0;
    while(k--)
    {
    	ll dx, dy;
    	cin >> dx >> dy;

    	ll steps = 0;
    	ll l = 0, r = 1e9+9, mid;
    	while(l <= r)
    	{
    		mid = l + (r-l)/2;
    		if(valid(x+(mid*dx), y+(mid*dy), n, m))
    		{
    			steps = mid;
    			l = mid+1;
    		}
    		else
    		{
    			r = mid-1;
    		}
    	}

    	answer += steps;
    	x = x + (dx*steps);
    	y = y + (dy*steps);
    }

    cout << answer << endl;

	return 0;
}