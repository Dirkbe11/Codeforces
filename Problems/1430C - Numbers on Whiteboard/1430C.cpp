
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

        if(n == 1)
	{
	    std::cout << 1 << "\n";
	    continue;
	}

	std::cout << "2" << "\n";

	std::multiset<int> vals;
	for(int i = 1; i <= n; i++)
	    vals.insert(i);

	while(vals.size() != 1)
	{
	    auto it = vals.end();
	    it--;
	    int a = *it;
	    it--;
	    int b = *it;
	    
	    std::cout << a << " " << b << "\n";
	    
	    int newVal = (a+b+1)/2;
	    vals.erase(a);
	    vals.erase(b);
	    vals.insert(newVal);
	}	
    }


    

    return 0;
}
