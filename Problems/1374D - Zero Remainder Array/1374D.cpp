
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
	int n, k;
	cin >> n >> k;

	std::map<ll, ll> mapper;

	long long result = 0;
	for(int i = 0; i < n; i++)
	{
	    ll num;
	    cin >> num;

	    ll val = k-(num%k);
	    
	    if(num%k)
	    {
		mapper[val]++;

		ll res = (k*(mapper[val]-1) + val+1);
		result = max(result, res);
	    }
	}

	std::cout << result << "\n";
    }

    return 0;
}
 
