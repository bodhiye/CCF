#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define N 20001

using namespace std;

int n, m, ans, p;
bool inq[N];
int d[N];
vector<int> g[N];
queue<int> q;

void bfs(int u)
{
	memset(d, 0, sizeof(d));
	memset(inq, false, sizeof(inq));
	q.push(u);
	inq[u] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			if (!inq[v])
			{
				q.push(v);
				inq[v] = true;
				d[v] = d[u] + 1;
				if (ans<d[v])
				{
					ans = d[v];
					p = v;
				}
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	int x, y = 1;
	while (--n)
	{
		cin >> x;
		g[x].push_back(++y);
		g[y].push_back(x);
	}
	while (--m)
	{
		cin >> x;
		g[x].push_back(++y);
		g[y].push_back(x);
	}
	bfs(1), bfs(p);
	cout << ans << endl;
	return 0;
}