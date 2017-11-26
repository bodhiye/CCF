#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> v[1001];
int a[1001][1001];

void dfs(int x, int *visit, int y)
{
	visit[x] = 1;
	a[x][y] = a[y][x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (visit[v[x][i]] == 0)
		{
			dfs(v[x][i], visit, y);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		int visit[1001] = { 0 };
		dfs(i, visit, i);
	}
	for (int i = 1; i <= n; i++)
	{
		int j;
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] == 0)
			{
				break;
			}
		}
		if (j == n + 1)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

//#include <iostream>
//
//using namespace std;
//
//int pre[1001], n, m, a, b, ans;
//
//void init()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		pre[i] = i;
//	}
//}
//
//int find(int x)
//{
//	if (x == pre[x])
//	{
//		return x;
//	}
//	return pre[x] = find(pre[x]);
//}
//
//void join(int x, int y)
//{
//	int x1 = find(x);
//	int y1 = find(y);
//	if (x1 != y1)
//	{
//		pre[y1] = x1;
//	}
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin >> n >> m;
//	init();
//	while (m--)
//	{
//		cin >> a >> b;
//		join(a, b);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (i == pre[i])
//		{
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}