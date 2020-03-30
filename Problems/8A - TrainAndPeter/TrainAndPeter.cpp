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

vector<int> lps(string& word)
{
	vector<int> lp(word.length(),0);

	int index = 0;
	for(int i = 1; i < word.length();)
	{
		if(word[index] == word[i])
		{
			index++;
			lp[i] = index;
			i++;
		}
		else
		{
			if(index)
				index = lp[index-1];
			else
				i++;
		}
	}

	return lp;
}

bool KMP(string& word, string& text)
{
	vector<int> lp = lps(word);

	int wordIndex = 0, textIndex = 0;
	while(wordIndex < word.length() && textIndex < text.length())
	{
		if(word[wordIndex] == text[textIndex])
		{
			wordIndex++;
			textIndex++;
		}
		else
		{
			if(wordIndex)
				wordIndex = lp[wordIndex-1];
			else
				textIndex++;
		}
	}


	text = text.substr(textIndex);
	return wordIndex == word.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string flagSequence;
    cin >> flagSequence;

    string firstSequence, secondSequence;
    cin >> firstSequence >> secondSequence;

    string f = flagSequence;
    bool forward = KMP(firstSequence, f) && KMP(secondSequence, f);
    reverse(flagSequence.begin(), flagSequence.end());
    bool backward = KMP(firstSequence, flagSequence) && KMP(secondSequence, flagSequence);

    if(forward && backward)
    	std::cout << "both";
    else if(forward && !backward)
    	std::cout << "forward";
    else if(!forward && backward)
    	std::cout << "backward";
    else
    	std::cout << "fantasy";

	return 0;
}