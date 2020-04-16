
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

std::vector<vector<int>> ProcessCharPlacement(string& word, int k)
{
	std::vector<vector<int>> alpha(k, vector<int>(26, 0));

	for(int i = 0; i < word.length(); i++)
	{
		alpha[i%k][word[i]-'a']++;
	}

	return alpha;
}

int difference(int u, int v, std::vector<vector<int>>& alpha)
{
	int mx = 0;
	int total = 0;
	for(int i = 0; i < 26; i++)
	{
		mx = max(mx, alpha[u][i] + alpha[v][i]);
		total += alpha[u][i] + alpha[v][i];
	}

	return total - mx;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases; cin >> testCases;
    while(testCases--)
    {
    	int n; cin >> n;
    	int k; cin >> k;

    	string word;
    	cin >> word;

    	std::vector<vector<int>> alpha = ProcessCharPlacement(word, k);

    	int result = 0;

    	for(int i = 0; i < k; i++)
    	{
    		result += difference(i, k-i-1, alpha);
    	}

    	std::cout << result/2 << "\n";

    }

	return 0;
}