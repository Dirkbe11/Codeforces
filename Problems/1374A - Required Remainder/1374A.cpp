
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
        int x, y, n;
	cin >> x >> y >> n;

	int result = n-((n-y)%x);
	std::cout << result << std::endl;
    }

    return 0;
}
