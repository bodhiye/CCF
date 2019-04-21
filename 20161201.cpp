#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int m = n / 2;
	int left = m, right = n - m - 1;
	for (int i = m-1; i >= 0; i--)
	{
		if (a[i] == a[m])
		{
			left--;
		}
		else
		{
			break;
		}
	}
	for (int i = m + 1; i < n; i++)
	{
		if (a[i] == a[m])
		{
			right--;
		}
		else
		{
			break;
		}
	}
	if (left == right)
	{
		cout << a[m] << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}