#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100001

using namespace std;

long long p[N], ans;
bool vis[N];
typedef pair<int, int> Pair;
vector<Pair> g[N];

void dfs(int s, int t, long long price)
{
	long long minprice;
	long long cost;
	if (s == t)
	{
		cout << ans << endl;
	}
	else
	{
		vis[s] = true;
		for (int i = 0; i < g[s].size(); i++)
		{
			if (!vis[g[s][i].first])
			{
				minprice = min(price, p[s]);
				cost = g[s][i].second*minprice;
				ans += cost;
				dfs(g[s][i].first, t, minprice);
				ans -= cost;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	while (--n)
	{
		int u, v, e;
		cin >> u >> v >> e;
		g[u].push_back(Pair(v, e));
		g[v].push_back(Pair(u, e));
	}
	while (m--)
	{
		int s, t;
		cin >> s >> t;
		memset(vis, false, sizeof(vis));
		ans = 0;
		dfs(s, t, p[s]);
	}
	return 0;
}