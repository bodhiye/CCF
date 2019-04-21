#include <iostream>

using namespace std;

int n, m, l, r, v, flag, a[100001];
long long t[100001];//定义树状数组

int lowbit(int x)//清除x的二进制高位1
{
	return x & (-x);
}

void change(int x, int p)//将第x个数加p
{
	while (x <= n)
	{
		t[x] += p;
		x += lowbit(x);
	}
}

long long sum(int k)//前k个数的和
{
	long long ans = 0;
	while (k > 0)
	{
		ans += t[k];
		k -= lowbit(k);
	}
	return ans;
}

long long ask(int l, int r)//求l-r区间和
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