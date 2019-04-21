#include <iostream>
#include <cmath>

using namespace std;

int a[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	cin >> a[0];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		int tmp = abs(a[i] - a[i - 1]);
		if (tmp > ans)
		{
			ans = tmp;
		}
	}
	cout << ans << endl;
	return 0;
}