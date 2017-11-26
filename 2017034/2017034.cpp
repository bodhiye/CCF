#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int a, b, c;
};

int pre[100001], n, m, ans;
node d[200001];

bool cmp(node x, node y)//自定义结构体排序函数
{
	return x.c < y.c;
}

void init()//初始化并查集数组
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = i;
	}
}

int find(int x)//并查集查询函数
{
	if (x == pre[x])
	{
		return x;
	}
	return pre[x] = find(pre[x]);//路径压缩
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++)
	{
		cin >> d[i].a >> d[i].b >> d[i].c;
	}
	sort(d, d + m, cmp);
	for (int i = 0; i < m; i++)
	{
		int x = find(d[i].a);
		int y = find(d[i].b);
		if (x != y)
		{//设置父元素
			if (x > y)
			{
				pre[x] = y;
			}
			else
			{
				pre[y] = x;
			}
			ans = max(ans, d[i].c);
		}
		if (1 == find(n))//如果1-n连通，则输出结果
		{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}