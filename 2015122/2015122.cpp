#include <iostream>

using namespace std;

int a[31][31], b[31][31];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] || a[i][j] == a[i][j - 1] && a[i][j] == a[i][j + 1] || a[i][j] == a[i][j - 1] && a[i][j] == a[i][j - 2] || a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] || a[i][j] == a[i - 1][j] && a[i][j] == a[i + 1][j] || a[i][j] == a[i - 1][j] && a[i][j] == a[i - 2][j])
				b[i][j] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	return 0;
}