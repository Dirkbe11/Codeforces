
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

	int result = 0;
	int primaryElement = 0;
	int secondaryElement = 0;
	std::vector<int> res;

	for(int i = 0; i < n; i++)
	{
	    int newVal;
	    cin >> newVal;

	    while(res.size() > 1 && (abs(newVal-res.back()) + abs(res.back()-res[res.size()-2]) <= abs(newVal - res[res.size()-2])))
	    {
		res.pop_back();
	    }

	    res.push_back(newVal);
	}

	std::cout << res.size() << "\n";
	for(int i = 0; i < res.size()-1; i++)
	    std::cout << res[i] << " ";
	std::cout << res.back() << "\n";
	    
    }

    return 0;
}

