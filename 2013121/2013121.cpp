#include <iostream>

using namespace std;

int a[10001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, tmp, ans=1, max = 0;
	cin >> n;
	while(n--)
	{
		cin >> tmp;
		a[tmp]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (a[i] > max)
		{
			ans = i;
			max = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}