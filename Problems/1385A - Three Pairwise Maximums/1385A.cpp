
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
    	int x, y, z;
    	cin >> x >> y >> z;

    	vector<int> aOption{x, y};
    	vector<int> bOption{z, x};
    	vector<int> cOption{y, z};

    	bool found = false;
    	int a, b, c;
    	for(int i = 0; i < 2; i++)//a
    	{
    		for(int j = 0; j < 2; j++)//b
    		{
    			for(int k = 0; k < 2; k++)//c
    			{
    				if(x == max(aOption[i], bOption[j]) &&
    				   y == max(aOption[i], cOption[k]) &&
    				   z == max(bOption[j], cOption[k]))
    				{
    					a = aOption[i];
    					b = bOption[j];
    					c = cOption[k];
    					found = true;
    					break;
    				}
    			}
    		}
    	}

    	if(found)
    	{
    		std::cout << "YES" << "\n";
    		std::cout << a << " " << b << " " << c << "\n";
    	}
    	else
    		std::cout << "NO" << "\n";

    }

	return 0;
}