
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
	ll N;
	cin >> N;

	ll result = 0;
	bool turn = true;
	
	while(N)
	{

	    if(N < 5)
	    {
		if(turn)
		    result += max(1ll, N-1);
		else
		    result += N-max(1ll,N-1);

		N = 0;
		continue;
	    }
	    
	    if(N % 4 != 0 && N % 2 == 0)
	    {
		if(turn)
		    result += (N/2);
		
		N /= 2;
	    }
	    else
	    {
		if(turn)
		    result++;
		
		N--;
	    }

	    turn = !turn;
	}

	std::cout << result << "\n";


    }

    return 0;
}
