
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

std::unordered_map<ll, unsigned int, custom_hash> memo;
						     
bool Solve(string& S, unsigned int AB = 0, unsigned int BA = 0, ll index = 0)
{
    if(AB && BA) return true;
    // ll key = (index << 32) ^ (AB << 2) ^ (BA);
    // if(memo.find(key) != memo.end()) return memo[key];

    for(int i = index; i < S.length()-1; i++)
    {
	if(!AB && S[i] == 'A' && S[i+1] == 'B' && Solve(S, 1, BA, i+2))
	    return true;
	if(!BA && S[i] == 'B' && S[i+1] == 'A' && Solve(S, AB, 1, i+2))
	    return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    string S;
    cin >> S;
    if(S.length() <= 3)
    {
	std::cout << "NO" << "\n";
        return 0;		     
    }

	bool result = Solve(S); 

    if(result)
	std::cout << "YES" << "\n";
    else
	std::cout << "NO" << "\n";
    return 0;
}
