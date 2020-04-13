
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


void printOptimal()
{
	std::cout << "OPTIMAL" << "\n";
}

void printImprove(int princess, int prince)
{
	std::cout << "IMPROVE" << "\n";
	std::cout << princess << " " << prince << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 0;
    cin >> testCases;

    while(testCases--)
    {
    	int princessesCount;
    	cin >> princessesCount;
    	if(!princessesCount)
    	{
    		printOptimal();
    		continue;
    	}

    	std::vector<int> princes(princessesCount+1, -1);
    	std::vector<int> princesses(princessesCount+1, -1);
    	princes[0] = princesses[0] = 0;

    	for(int i = 1; i <= princessesCount; i++)
    	{
    		int wishCount;
    		cin >> wishCount;

    		for(int j = 0; j < wishCount; j++)
    		{
    			int prince;
    			cin >> prince;

    			if(princes[prince] == -1 && princesses[i] == -1)
    			{
    				princesses[i] = prince;
    				princes[prince] = i;
    			}
    		}
    	}

    	auto princessIt = find(princesses.begin(), princesses.end(), -1);
    	auto princeIt = find(princes.begin(), princes.end(), -1);

    	if(princessIt != princesses.end() && princeIt != princes.end())
    		printImprove(princessIt - princesses.begin(), princeIt - princes.begin());
    	else
    		printOptimal();

    }

	return 0;
}