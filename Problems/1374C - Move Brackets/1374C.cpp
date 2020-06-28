
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
	int sLen;
	cin >> sLen;
	string s;
	cin >> s;
	
	int count = 0;
	int result = 0;
	for(auto c : s)
	{
	    if(c == ')')
		count--;
	    else
		count++;
	    
	    result = min(result, count);
	}

	std::cout << abs(result) << "\n";
    }
    return 0;
}
