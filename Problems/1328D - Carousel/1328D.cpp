
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> Solve(int n, vector<int>& figures, size_t size)
{
    if(size == 1)
    {
	return vector<int>(n+1, 1);
    }

    if(n%2 == 0)
    {
	vector<int> result;
	
	for(int i = 0; i < figures.size(); i++)
	{
	    if(i%2 == 0)
		result.push_back(1);
	    else
		result.push_back(2);
	    
	}
	result.push_back(2);
	return result;	
    }

    bool matched = false;
    std::vector<int> result({1});
    for(int i = 1; i < figures.size(); i++)
    {
	if(!matched && figures[i] == figures[i-1])
	{
	    matched = true;
	    result.push_back(result[i-1]);
	    continue;
	}
	else
	{
	    if(result[i-1] == 1)
		result.push_back(2);
	    else
		result.push_back(1);
	}
    }
    if(!matched && figures[0] == figures.back())
    {
	matched = true;
	result[result.size()-1] = 1;
    }
    

    if(matched)
    {
	result.push_back(2);
	return result;
    }

    result[result.size()-1] = 3;
    result.push_back(3);
    return result;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;

    while(testCases--)
    {
	int n;
	cin >> n;

	vector<int> figures(n);
	std::unordered_set<int> uniqueTypes;
	for(int i = 0; i < n; i++)
	{
	    cin >> figures[i];
	    uniqueTypes.insert(figures[i]);
	}

	std::vector<int> result = Solve(n, figures, uniqueTypes.size());
	std::cout << result.back() << "\n";
	result.pop_back();
	for(int i = 0; i < result.size()-1; i++)
	{
	    std::cout << result[i] << " ";
	}

	std::cout << result.back() << "\n";
    }
    
    return 0;
}
