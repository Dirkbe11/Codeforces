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
 
//Find the combination of M integers such that they add up to S
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int M, S;
    cin >> M >> S;
 
    if(!S && M != 1)
    {
	std::cout << "-1 -1" << "\n";
	return 0;
    }
 
    if(!S && M == 1)
    {
	std::cout << "0 0" << "\n";
	return 0;
    }
 
    string tester = to_string(S);
    if(tester.length() > M)
    {
	std::cout << "-1 -1" << "\n";
	return 0;
    }
 
    int div = S/M;
    if(div >= 10)
    {
	std::cout << "-1 -1" << "\n";
	return 0;
    }
 
    vector<int> numbers(M, div);
   
    int remainder = S%M;
    for(int i = 0; i < M && remainder; i++)
    {
	while(remainder && numbers[i] < 9)
	{
	    remainder--;
	    numbers[i]++;
	}
    }
 
 
    sort(numbers.begin(), numbers.end());
    int i = 0, j = numbers.size()-1;
 
    while(i < j)
    {
	if(numbers[i] == 0)
	    i++;
	else if(numbers[j] == 9)
	    j--;
	else
	{
	    numbers[i]--;
	    numbers[j]++;
	}
    }
 
    int summation = accumulate(numbers.begin(), numbers.end(), 0);
    if(summation != S)
    {
	std::cout << "-1 -1" << "\n";
	return 0;
    }
 
    sort(numbers.begin(), numbers.end());
 
    string smallest("");
    for(auto i : numbers)
    {
	smallest += (i+'0');
    }
 
    string biggest(smallest.rbegin(), smallest.rend());
 
 
    if(biggest[0] == '0')
    {
	std::cout << "-1 -1" << "\n";
	return 0;
    }
 
    int k = 0;
    while(smallest[k] == '0')
    {
	k++;
    }
    int target = smallest[k]-'0';
    if(k)
    {
	smallest[0] = '1';
	smallest[k] = (target-1) + '0';
    }
 
    std::cout << smallest << " " << biggest << "\n";
    
    return 0;
}
