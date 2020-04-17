
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

void GetMonsterStats(vector<ll>& monstersHealth, vector<ll>& monsterBoom, int n)
{
     for(int i = 0; i < n; i++)
        {
            ll health;
            cin >> health;
            ll boom;
            cin >> boom;
            monstersHealth.push_back(health);
            monsterBoom.push_back(boom);
        }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;
    while(testCases--)
    {
        int n;
        cin >> n;

        vector<ll> monsterHealth;
        vector<ll> monsterBoom;
        GetMonsterStats(monsterHealth, monsterBoom, n);

        ll result = 0;
        ll mn = 1e18;
        for(int i = 0; i < n; i++)
        {
            int target = (i+1)%n;
            ll val = min(monsterHealth[target], monsterBoom[i]);
            result += monsterHealth[target] - val;
            mn = min(mn, val);
        }

        result += mn;

        std::cout << result << "\n";
    }

    return 0;
}