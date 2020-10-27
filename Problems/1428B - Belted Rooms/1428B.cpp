
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

	string s;
	cin >> s;

	bool stuck = false;
	int leftCount = 0;
	int rightCount = 0;
	int offcount = 0;

        for(int i = 0; i < n; i++)
	{
	    char belt1, belt2;
	    if(!i)
		belt1 = s.back();
	    else
		belt1 = s[i-1];

	    belt2 = s[i];

	    leftCount += (belt1 == '<' || belt2 == '<');
	    rightCount += (belt1 == '>' || belt2 == '>');
	    
	    offcount += (belt1 == '-' || belt2 == '-');
	}

	stuck = !(!leftCount || !rightCount);

	if(stuck)
	    std::cout << offcount << "\n";
	else
	    std::cout << n << "\n";
    }

    return 0;
}
