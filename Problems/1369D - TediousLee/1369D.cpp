
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr const int MOD = 1e9 + 7;
int dp[int(2e6+7)];

void Answer(int x)
{
    std::cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0] = dp[1] = 0;
    dp[2] = 4;

    for(int i = 3; i < int(2e6+7); i++)
    {
	ll w = dp[i-1];
        w += 2*dp[i-2] + (i%3 == 2)*4;
        w %= MOD;
	dp[i] = w;
     }

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
	int n;
	cin >> n;

	std::cout << dp[n-1] << "\n";
    }

    return 0;
}
