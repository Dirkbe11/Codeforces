
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
	int n, q;
	cin >> n >> q;

	ll result = 0;

	int current = INT_MIN;
	int minimal = INT_MIN;
	int secondary = 0;
	for(int i = 0; i < n; i++)
	{
	    ll num;
	    cin>> num;

	    if(num >= current)
	    {
		result += current - minimal;
		current = minimal = num;
		secondary = 0;
	    }
	    else if(num > minimal)
	    {
		result += current - minimal;
		current = minimal = num;
		secondary = 0;
	    }
	    else if(num < minimal)
	    {
		minimal = num;
	    }
	}

	if(minimal != INT_MIN)
	    minimal = min(minimal, 0);

	std::cout << result + (current-minimal) << "\n";

    }
    return 0;
}
