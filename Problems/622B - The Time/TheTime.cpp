/**
    __author__ : Kodex
    problems_ID:
*/

#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;


void solve(string& hour, string& minute, int a)
{
	int hours = stoi(hour);
	int minutes = stoi(minute);

	int carryover = 0;

	carryover = (a+minutes)/60;
	minute = to_string((a+minutes)%60);


	if(carryover)
	{
		hour = to_string((hours + carryover)%24);
	}
	if(hour.length() == 1)
		hour = "0" + hour;
	if(minute.length() == 1)
		minute = "0" + minute;

	std::cout << hour+":"+minute;
}


int main() {
    ios::sync_with_stdio(false);

    string time;
    cin >> time;
    stringstream ss(time);
    string hours;
    string minutes;
    getline(ss, hours, ':');
    getline(ss, minutes, ':');

    int a;
    cin >> a;
    if(!a)
    	std::cout << time;
    else
    	solve(hours, minutes, a);
    
	return 0;
}