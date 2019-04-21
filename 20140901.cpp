#include <iostream>
#include <algorithm>

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
	sort(a, a + n);
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[i - 1] == 1)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}