#include <iostream>

using namespace std;

int a[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, ans = 1;
	cin >> n;
	cin >> a[0];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		if (a[i] != a[i - 1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}