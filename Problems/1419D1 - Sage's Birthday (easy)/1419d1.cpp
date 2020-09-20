#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<int> spheres(n, 0);
 
    for(int i = 0; i < n; i++)
	cin >> spheres[i];

    sort(spheres.begin(), spheres.end());
    if(n <= 2)
    {
	std::cout << 0 << "\n";
	for(auto num : spheres)
	    std::cout << num << " ";

	return 0;
    }
 
    for(int i = 1; i < n-1; i++)
    {
	if(i&1 && spheres[i] > spheres[i-1])
	    swap(spheres[i], spheres[i-1]);
    }
 
 
    std::cout << (n-2)/2 + (n % 2 == 1 ? 1 : 0) << "\n";
 
    for(auto num : spheres)
	std::cout << num << " ";
 
    std::cout << "\n";
    return 0;
}
