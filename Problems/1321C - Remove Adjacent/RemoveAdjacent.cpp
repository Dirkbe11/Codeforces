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

    int sLen;
    cin >> sLen;

    string sampling;
    cin >> sampling;

   	int result = 0;

   	bool removedElement = true;
   	while(removedElement)
   	{
   		int maximalIndex = -1;
   		char maximalCharacter = 'a';

   		if(sampling.length() > 1 && (sampling[0] - sampling[1]) == 1)
		{
			maximalIndex = 0;
			maximalCharacter = sampling[0];
		}

   		for(int i = 1; i < sampling.length()-1; i++)
   		{
   			if((sampling[i]-sampling[i-1] == 1 || sampling[i]-sampling[i+1] == 1) && maximalCharacter < sampling[i])
   			{
   				maximalIndex = i;
   				maximalCharacter = sampling[i];
   			}
   		}

   		if(sampling.length() > 1 && sampling[sampling.length()-1] - sampling[sampling.length()-2] == 1 && maximalCharacter < sampling[sampling.length()-1])
		{
			maximalIndex = sampling.length()-1;
			maximalCharacter = sampling[sampling.length()-1];
		}

		if(maximalIndex != -1)
		{
			result++;
			sampling.erase(sampling.begin()+maximalIndex);
		}

		removedElement = (maximalIndex != -1);
   	}

   	std::cout << result;

	return 0;
}