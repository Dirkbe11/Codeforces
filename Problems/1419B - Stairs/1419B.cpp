
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cellsNeeded(ll x)
{
    return x * (x+1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
	ll x;
	cin >> x;

	ll result = 0;

	for(int i = 1; cellsNeeded((1LL << i) -1) <= x; i++)
	{
	    result++;
	    x -= cellsNeeded((1LL << i) -1);
	}

	std::cout << result << "\n";
	
    }
    return 0;
}
