/**
    __author__ : Kodex
    problems_ID:
*/

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

void solve(int n, int m, vector<vector<char>>& matrix)
{
	int maxx = -1, minx = n, maxy = -1, miny = m;
	int count = 0;
	for(int i = 0; i < matrix.size(); i++)
	{
		for(int j = 0; j < matrix[i].size(); j++)
		{
			if(matrix[i][j] != 'X') continue;

			maxx = max(maxx, i);
			minx = min(minx, i);
			maxy = max(maxy, j);
			miny = min(miny, j);
			count++;
		}
	}

	cout << (((maxx-minx+1)*(maxy-miny+1) == count) ? "YES" : "NO");
}


int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int count = 0;
    std::vector<vector<char>> matrix(n, vector<char>(m, '.'));

    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		char c;
    		cin >> c;
    		matrix[i][j] = c;
    	}
    }

    	solve(n, m, matrix);

	return 0;
}