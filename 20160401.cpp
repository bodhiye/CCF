#include <iostream>

using namespace std;

int a[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
		{
			ans++;
		}
		else if (a[i] < a[i - 1] && a[i] < a[i + 1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}