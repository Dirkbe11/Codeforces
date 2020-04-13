
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

    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    std::vector<int> desiredSizes;
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> temp;
    	desiredSizes.push_back(temp);
    }

   	std::vector<int> availableSizes;
   	for(int i = 0; i < m; i++)
   	{
   		cin >> temp;
   		availableSizes.push_back(temp);
   	}


   	int result = 0;
   	std::unordered_map<int, int> mapping;
   	int desiredIndex = 0, availableIndex = 0;

   	while(desiredIndex <= n-1 && availableIndex <= m-1)
   	{
   		if(availableSizes[availableIndex]  >= desiredSizes[desiredIndex] - x &&  availableSizes[availableIndex] <= desiredSizes[desiredIndex] + y)
   		{
   			result++;
   			mapping[desiredIndex+1] = availableIndex+1;
   			desiredIndex++;
   			availableIndex++;
   		}
   		else if(availableSizes[availableIndex] < desiredSizes[desiredIndex] - x)
   		{
   			availableIndex++;
   		}
   		else if(availableSizes[availableIndex] > desiredSizes[desiredIndex] + y)
   		{
   			desiredIndex++;
   		}
   	}

   	std::cout << result << "\n";
   	for(auto p : mapping)
   		std::cout << p.first << " " << p.second << "\n";

	return 0;
}