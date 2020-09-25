
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
	int n;
	cin >> n;

	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	auto customSort = [](int a, int b){return a <= b;};
	
	if(is_sorted(nums.rbegin(), nums.rend(), customSort))
	    std::cout << "NO\n";
	else
	    std::cout << "YES\n";
    }
    return 0;
}
