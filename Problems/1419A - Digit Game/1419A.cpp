
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
	int n;
	cin >> n;

	string s;
	cin >> s;

	if(s.length() == 1)
	{
	    if(stoi(s) % 2 == 1)
		std::cout << 1 << "\n";
	    else
		std::cout << 2 << "\n";
	}
	else
	{
	    int even = 0;
	    int odd = 0;

	    for(int i = 0; i < n; i++)
	    {
		if(i % 2 == 0)
		    odd += (s[i]%2) == 1;
		else
		    even += (s[i]%2) == 0;
	    }


	    if(s.length()%2 == 0)
		std::cout << (even > 0 ? 2 : 1) << "\n";
	    else
		std::cout << (odd > 0 ? 1 : 2) << "\n";
	}

	
	
    }
    return 0;
}
