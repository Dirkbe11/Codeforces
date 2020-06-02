
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

int prefixSum[100001];

int Query(int l, int r)
{
    if(l < 0) return prefixSum[r];
    return prefixSum[r] - prefixSum[l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    for(int i = 0; i < 100001; i++)
	prefixSum[i] = 0;

    for(int i = 1; i < 100001; i++)
    {
	prefixSum[i] = prefixSum[i-1];
	if(i < s.length() && s[i] == s[i-1])
	{
	    prefixSum[i-1]++;
	    prefixSum[i]++;
	}
    }

    int m;
    cin >> m;
    for(int i= 0; i < m; i++)
    {
	int l, r;
	cin >> l >> r;

	std::cout << Query(l-2, r-2) << "\n";
    }

    
    return 0;
}