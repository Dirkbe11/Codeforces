
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> ab{INT_MAX};
    vector<ll> a{INT_MAX};
    vector<ll> b{INT_MAX};

    for(int i = 0; i < n; i++)
    {
	int time, al, bl;
	cin >> time >> al >> bl;

	if(al && bl)
	    ab.push_back(time);
	else if(al)
	    a.push_back(time);
	else if(bl)
	    b.push_back(time);
    }

    if(ab.size() + a.size() - 2 < k || ab.size() + b.size() - 2 < k)
    {
	std::cout << "-1\n";
	return 0;
    }
    
    sort(ab.rbegin(), ab.rend());
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int result = 0;
    int alice = 0, bob = 0;

    while(alice < k && bob < k)
    {
        if(ab.back() < a.back() + b.back())
	{
	    result += ab.back();
	    ab.pop_back();
	    alice++, bob++;
	}
	else
	{
	    result += a.back() + b.back();
	    a.pop_back(), b.pop_back();
	    alice++, bob++;
	}
    }

    while(alice < k)
    {
	if(ab.back() < a.back())
	{
	    result += ab.back();
	    ab.pop_back();
	    alice++;
	}
	else
	{
	    result += a.back();
	    a.pop_back();
	    alice++;
	}
    }

    while(bob < k)
    {
	if(ab.back() < b.back())
	{
	    result += ab.back();
	    ab.pop_back();
	    bob++;
	}
	else
	{
	    result += b.back();
	    b.pop_back();
	    bob++;
	}
    }

    if(!(alice >= k && bob >= k))
	std::cout << "-1\n";
    else
	std::cout << result << "\n";
	

    return 0;
}
