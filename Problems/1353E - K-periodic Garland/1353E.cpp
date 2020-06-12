
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//we have the total number of ones that would need to be removed
//Now we need to find the minimum number of ones/zeroes that need to change
//in each period in order to be valid
int Solve(string& period)
{
    int totalOnes = count(period.begin(), period.end(), '1');

    int result = min(totalOnes, int(period.length()) - totalOnes); //initialized so that we change all the ones or zeroes

    int runningSum = 0;
    
     for(int i = 0 ; i < period.length(); i++)
     {
	
   	if(period[i] == '1')
	    runningSum++;
    	else
	    runningSum--;

    	result = min(result, totalOnes-runningSum);
    	runningSum = max(runningSum, 0);
    }

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
	int n, k;
	cin >> n >> k;
	std::vector<string> periods(k, "");

	int totalOnes = 0;
	for(int i = 0; i < n; i++)
	{
	    char temp;
	    cin >> temp;
	    periods[i%k] += temp;

	    if(temp == '1')
		totalOnes++;
	}
	
	int result = totalOnes;
	for(int i = 0; i < periods.size(); i++)
	{
	    result = min(result, int((totalOnes - count(periods[i].begin(), periods[i].end(), '1') ))+ Solve(periods[i]));
	}

	std::cout << result << "\n";
    }
    return 0;
}

