
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int k;
    cin >> k;

    if(s.length() == 0 || s.length() == 1)
    {
    	std::cout << ((k + s.length())/2)*2 << "\n";
    	return 0;
    }

    for(int i = 0; i < k; i++)
    	s += "?";

    int result = 0;
    for(int i = 0; i <= s.length()-2; i++)
    {
    	int temp = 0;
    	for(int len = 1; len <= (s.length()-i+1)/2; len++)
    	{
    		bool flag = true;
    		for(int j = i; j <= i+len-1; j++)
    		{
    			if(s[j] != s[j+len])
    			{
    				if(s[j+len] != '?' && s[j] != '?')
    				{
    					flag = false;
    					break;
    				}
    			}
	    		if(j + len >= s.length())
	    		{
	    			flag = false;
	    			break;
	    		}
    		}

			if(flag)
			{
				result = max(result, len);
			}

    	}
    }

    std::cout << result*2 << std::endl;

	return 0;
}