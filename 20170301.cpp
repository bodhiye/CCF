#include <iostream>

using namespace std;

int a[1001], n, k, temp, ans;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		temp += a[i];
		if (temp >= k)
		{
			temp = 0;
			ans++;
		}
	}
	if (temp)
	{
		ans++;
	}
	cout << ans << endl;
	return 0;
}