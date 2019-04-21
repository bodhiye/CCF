#include <iostream>

using namespace std;

int n, m, l, r, v, flag, a[100001];
long long t[100001];//������״����

int lowbit(int x)//���x�Ķ����Ƹ�λ1
{
	return x & (-x);
}

void change(int x, int p)//����x������p
{
	while (x <= n)
	{
		t[x] += p;
		x += lowbit(x);
	}
}

long long sum(int k)//ǰk�����ĺ�
{
	long long ans = 0;
	while (k > 0)
	{
		ans += t[k];
		k -= lowbit(k);
	}
	return ans;
}

long long ask(int l, int r)//��l-r�����
{
	return sum(r) - sum(l - 1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		change(i, a[i]);
	}
	while (m--)
	{
		cin >> flag;
		if (flag == 1)
		{
			cin >> l >> r >> v;
			if (v == 1) continue;
			for (int i = l; i <= r; i++)
			{
				if (a[i] >= v && a[i] % v == 0)
				{
					change(i, a[i] / v - a[i]);
					a[i] /= v;
				}
			}
		}
		else if (flag == 2)
		{
			cin >> l >> r;
			cout << ask(l, r) << endl;
		}
	}
	return 0;
}