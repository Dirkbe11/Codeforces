
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dp[100001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
	int n, t;
	cin >> n >> t;

	std::unordered_map<int, int> seent;

	for(int i = 0; i < n; i++)
	{
	    int num;
	    cin >> num;

	    int target = t-num;

	    if(seent.find(target) != seent.end())
	    {
		if(seent[target] == 1)
		    dp[i] = 0;
		else
		    dp[i] = 1;

		seent[num] = dp[i];
	    }
	    else
	    {
		seent[num] = 1;
		dp[i] = 1;
	    }
	       
	}


	for(int i = 0; i < n; i++)
	    std::cout << dp[i] << " ";
	
	std::cout << "\n";
    }
    

	return 0;
}
