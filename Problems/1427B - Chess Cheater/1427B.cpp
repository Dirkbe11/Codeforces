
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
	int N, k;
	cin >> N >> k;

	string s;
	cin >> s;

	vector<int> indices;

	int lastW = 0;
	bool broken = false;
	int trailingLs = 0;
	int lCount = s[0] == 'L';
	int wCount = s[0] == 'W';
	int leadingLs = s[0] == 'L';
	int result = s[0] == 'W';
	
	for(int i = 1; i < s.length(); i++)
	{
	    wCount += s[i] == 'W';
	    lCount += s[i] == 'L';

	    if(s[i] == 'W')
		trailingLs = 0;
	    else
		trailingLs++;
	    
	    if(!wCount)
		leadingLs += s[i] == 'L';

	    if(s[i] == 'W' && s[i-1] == 'W')
		result += 2;
	    else if(s[i] == 'W' && s[i-1] == 'L')
		result++;
	    
	    if(s[i-1] == 'W' && s[i] == 'L')
	    {
		lastW = i-1;
		broken = true;
	    }
	    else if(s[i] == 'W' && broken)
	    {
		broken = false;
		indices.push_back(i-lastW-1);
	    }
	}
	
	if(lCount == 0)
	{
	    std::cout << result << std::endl;
	    continue;
	}

	sort(indices.begin(), indices.end());
        for(int i = 0; i < indices.size() && k > 0; i++)
	{
	    if(indices[i] <= k)
		result += (indices[i]*2)+1;
	    else
		result += (k*2);

	    k = max(0, k-indices[i]);
	}

	

	if(wCount && k && trailingLs)
	{
	    
	   result += (min(k, trailingLs) * 2);	    
	   k = max(0, k-trailingLs);
	}

	
	if(k && k >= leadingLs)
	{
	    if(wCount)
		result += (leadingLs*2);
	    else
		result += (leadingLs*2)-1;
	    k -= leadingLs;
	}
	else if(k)
	{
	    if(wCount)
		result += (k*2);
	    else
		result += (k*2)-1;
	}

	std::cout << result << std::endl;

	
    }
    

    return 0;
}
