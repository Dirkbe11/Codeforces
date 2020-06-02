
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


string Solve(vector<int>& digits)
{
    if(digits.size() == 0) return "-1";
    
    string result("");

    for(int i = 0; i < digits.size(); i++)
    {
	result += digits[i] + '0';
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin >> v;
    std::vector<int> costs(10, INT_MAX);
    int cheapestDigit = 1;
    int cheapestDigitCost = INT_MAX;
    for(int i = 1; i <= 9; i++)
    {
	cin >> costs[i];

	if(costs[i] <= cheapestDigitCost)
	{
	    cheapestDigit = i;
	    cheapestDigitCost = costs[i];
	}
    }


    if(cheapestDigitCost > v)
    {
	std::cout << -1 << "\n";
	return 0;
    }

    std::vector<int> digit(v/cheapestDigitCost, cheapestDigit);
    v%=cheapestDigitCost;
    
    int digitIndex = 9;

    for(int i = 0; i < digit.size() && digitIndex >= 1; i++)
    {
	while(digitIndex && v + cheapestDigitCost < costs[digitIndex])
	{
	    digitIndex--;
	}
	
	if(!digitIndex) break;
	if(digit[i] >= digitIndex) break;
	if(digit[i] >= digitIndex) break;
	v += cheapestDigitCost; 
	v -= costs[digitIndex];

	digit[i] = digitIndex;
    }

    

    std::cout << Solve(digit) << "\n";

    
    return 0;
}
