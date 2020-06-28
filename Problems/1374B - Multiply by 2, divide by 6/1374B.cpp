
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases;
    cin >> testcases;
    std::unordered_map<int, bool> memo;
    
    while(testcases--)
    {
	int n;
	cin >> n;
	std::unordered_set<int> seent;
	
	std::deque<int> dq;
	dq.push_back(n);

	int moves = 0;
	bool found = false;
	while(!dq.empty())
	{
	    int dqSize = dq.size();
	    for(int i = 0; i < dqSize; i++)
	    {
		int num = dq.front();
		dq.pop_front();
		if(seent.count(num) || num > 2*n) continue;
		seent.insert(num);

		if(num == 1)
		{
		    found = true;
		    break;
		}
		if(num == 0)
		{
		    moves = -1;
		    break;
		}

		if(num%6 == 0)
		    dq.push_back(num/6);
		dq.push_back(num*2);
	    }
	    
	    if(found) break;
	    
	    moves++;
	}

	if(found)
	    std::cout << moves << "\n";
	else
	    std::cout << "-1\n"; 
    }
	
	
    return 0;
} 
