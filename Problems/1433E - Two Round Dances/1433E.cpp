
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll factorial(ll x)
{
    if(x <= 1)
	return 1;

    return x*factorial(x-1);
}

ll NcK(ll N, ll K)
{
    return factorial(N)/(factorial(K)*factorial(N-K));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;


    ll result = NcK(N, N/2);

    std::cout << (result * factorial((N/2) - 1) * factorial((N/2)-1))/2<< std::endl;

    
    return 0;
}
