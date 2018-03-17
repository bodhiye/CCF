#include <iostream>
#include <cmath>

using namespace std;

int a[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, tmp, ans = 0;
	cin >> n;
	while (n--)
	{
		cin >> tmp;
		a[abs(tmp)]++;
	}
	for (int i = 1; i <= 1000; i++)
	{
		if (a[i] == 2)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}