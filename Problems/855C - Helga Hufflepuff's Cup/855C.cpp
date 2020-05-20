
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
typedef unordered_map<int, vector<int>> edgeList;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

/*
WoWoWoW!! this problem is very fun!

Essentially, we will use a combination of dynamic programming and DFS to solve this guy. 

We keep a 3D DP matrix
-where dp[i][j][c] means at node i, and {j | 0, 1, 2} means the current vault security level is less than k [0], equal
to k[1], or greater than k[2].

We first perform dfs on all nodes, and intitialize the values in the matrix correctly.

Then at each node, we essentially "combine" the results of each of our current node's children by mashing together [multiplying]
two children nodes together at a time.

we start at the first child and compute the base results, then we store these results in the second dp matrix, a. When we move on to the next child
node, we willa gain compute the base results, and then we will multiple this by the appropriate results in a. The l and r variables
mean that l max security nodes were in the previous child and r max security nodes are in the current child.

Together, these should give us the desired result.
*/
//# vaults, lower than k/k/higher than k, largest quantity of special vaults used
int dp[100005][3][12] = {0};
int a[3][12],b[3][12];
#define mod 1000000007
void SubmitResult(int x)
{
	std::cout << x%mod << std::endl;
}


//curr, parr, n, m, k, x,
void dfs(int cur, int par, int n, int m, int k, int x,  edgeList& q)
{
int i,j=0,l,r,temp;
	for(i=0;i<q[cur].size();i++)
	{
		if(q[cur][i]==par)
			continue;
		j=1;
		dfs(q[cur][i],cur, n, m, k, x, q);
	}
	if(!j)
	{
		dp[cur][0][0]=k-1;
		dp[cur][1][1]=1;
		dp[cur][2][0]=m-k;
		return;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<=x;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	for(i=0;i<3;i++)
		a[i][0]=1;
	for(i=0;i<q[cur].size();i++)
	{
		if(q[cur][i]==par)
			continue;
		for(j=0;j<3;j++)
		{
			for(l=0;l<=x;l++)
			{
				for(r=0;r<=x;r++)
				{
					if(l+r>x)
						continue;
					if(j==0)
					{
						temp=dp[q[cur][i]][0][r]+dp[q[cur][i]][1][r];
						if(temp>=mod)
							temp-=mod;
						temp+=dp[q[cur][i]][2][r];
						if(temp>=mod)
							temp-=mod;
						b[j][l+r]+=(1ll*a[j][l]*temp)%mod;
						if(b[j][l+r]>=mod)
							b[j][l+r]-=mod;
					}
					else if(j==1)
					{
						b[j][l+r]+=(1ll*a[j][l]*(dp[q[cur][i]][0][r]))%mod;
						if(b[j][l+r]>=mod)
							b[j][l+r]-=mod;
					}
					else
					{
						temp=dp[q[cur][i]][0][r]+dp[q[cur][i]][2][r];
						if(temp>=mod)
							temp-=mod;
						b[j][l+r]+=(1ll*a[j][l]*temp)%mod;
						if(b[j][l+r]>=mod)
							b[j][l+r]-=mod;
					}
				}
				
			}
		}
		for(j=0;j<3;j++)
		{
			for(l=0;l<=x;l++)
			{
				a[j][l]=b[j][l];
				b[j][l]=0;
			}
		}
	}
	for(l=0;l<=x;l++)
	{
		dp[cur][0][l]=(1ll*a[0][l]*(k-1))%mod;
		if(l>=1)
			dp[cur][1][l]=a[1][l-1];
		dp[cur][2][l]=(1ll*a[2][l]*(m-k))%mod;
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::unordered_map<int, vector<int>> edges;

    int n, m;
    cin >> n >> m;
    int result = 0;
    if(n == 0)
    {
    	SubmitResult(result);
    	return 0;
    }

    for(int i = 0; i < n-1; i++)
    {
    	int u, v;
    	cin >> u >> v;
    	edges[u].pb(v);
    	edges[v].pb(u);
    }

    int k, x;
    cin >> k >> x;

    dfs(1, 0, n, m, k, x, edges);

    for(int i = 0; i < 3; i++)
    {
    	for(int j = 0; j <= x; j++)
    	{
    		result += dp[1][i][j];
    		if(result >= mod) result -= mod;
    	}
    }

    std::cout << result << "\n";


	return 0;
}