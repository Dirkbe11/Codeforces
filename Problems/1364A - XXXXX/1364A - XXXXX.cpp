
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll prefixSum[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--)
    {
	int n, x;
	cin >> n >> x;

	int result = -1;
	int index1 = -1;
	int index2 = -1;
	int firstval = -1;
	int secondval = -1;
	prefixSum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
	    cin >> prefixSum[i];
	    prefixSum[i] += prefixSum[i-1];

	    if(index1 == -1)
	    {
		index1 = i;
		firstval = prefixSum[i]%x;
	    }
	    else if(index2 == -1 && prefixSum[i]%x != firstval)
	    {
		index2 = i;
		secondval = prefixSum[i]%x;
	    }

	    if((prefixSum[i]-prefixSum[1])%x != 0 )
	    {
		result = max(result, i-index1);
	    }
	    else if(index2 != -1 && (prefixSum[i]-prefixSum[index2])%x != 0)
	    {
		result = max(result,i-index2);
	    }
	    
	    if(prefixSum[i] % x != 0) result = i;
	}
	
	std::cout << result << "\n";

	

    }

   return 0;
}
