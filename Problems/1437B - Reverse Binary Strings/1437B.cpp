
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
	int n;
	cin >> n;

	std::string s;
	cin >> s;

	int double0 = 0;
	int double1 = 0;

	for(int i = 0; i < s.length()-1; i++)
	{
	    double0 += (s[i] == '0' && s[i+1] == '0');
	    double1 += (s[i] == '1' && s[i+1] == '1');
	}

	std::cout << max(double0, double1) << "\n";

    }

    return 0;
}
