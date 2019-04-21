#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int a, b, c;
};

int pre[100001], n, m, ans;
node d[200001];

bool cmp(node x, node y)//�Զ���ṹ��������
{
	return x.c < y.c;
}

void init()//��ʼ�����鼯����
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = i;
	}
}

int find(int x)//���鼯��ѯ����
{
	if (x == pre[x])
	{
		return x;
	}
	return pre[x] = find(pre[x]);//·��ѹ��
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
		{//���ø�Ԫ��
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
		if (1 == find(n))//���1-n��ͨ����������
		{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}