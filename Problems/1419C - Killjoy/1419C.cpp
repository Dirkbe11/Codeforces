#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
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
 
	int count = 0;

	int sum = 0;
	for(int i = 0; i < n; i++)
	{
	    int num;
	    cin >> num;
	    sum += (num - x);
	    if(num == x) continue;
 
	    count++;
	}
 
	if(count == 0)
	    std::cout << 0 << "\n";
	else if(count < n || sum == 0)
	    std::cout << 1 <<"\n";
	else
	    std::cout << 2 << "\n";
    }
 
    return 0;
}
