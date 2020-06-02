
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    std::vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++)
    {
	int coord, height;
	cin >> coord >> height;

	points[i] = make_pair(coord, height);
    }

    sort(points.begin(), points.end());
    
    int treesFelled = min(n, 2);
    int previousX = points[0].first;
    
    for(int i = 1; i < n-1; i++)
    {
	if(points[i].first - points[i].second > previousX)
	{
	    treesFelled++;
	    previousX = points[i].first;
	}
	else if(points[i].first + points[i].second < points[i+1].first)
	{
	    previousX = points[i].first + points[i].second;
	    treesFelled++;
	}
	else
	    previousX = points[i].first;
    }
    

    std::cout << treesFelled << "\n";

    
    return 0;
}
