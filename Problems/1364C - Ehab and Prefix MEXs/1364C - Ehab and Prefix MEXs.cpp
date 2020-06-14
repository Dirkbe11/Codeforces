
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
	cin >> a[i];
    a[0] = 0;

    std::vector<int> b(n+1, -1);
    std::vector<int> ex(n+1, 0);

    for(int i = 1; i <= n; i++)
    {
	if(a[i] != a[i-1])
	{
	    b[i] = a[i-1];
	    ex[b[i]] = 1;
	}
    }

    ex[a[n]] = 1;
    int m = 0;
    for(int i = 1; i <= n; i++)
    {
	while(ex[m]) m++;
	if(b[i] == -1)
	{
	    b[i] = m;
	    ex[m] = 1;
	}
	std::cout << b[i] << " ";
    }

    

    return 0;
}



/*
Seems almost like a topological sorting problem?

If there is a number in A, there must be at minimum val(Ai) spaces before that index in a

before we unlock a value, we must use all values before it

 */
