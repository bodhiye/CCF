#include <iostream>

using namespace std;

int a[20], b[101];

void solve(int p)
{
	int pos = 0;
	while (pos < 20)
	{
		if (a[pos] >= p)
			break;
		pos++;
	}
	if (pos == 20)
	{
		for (int i = 0; i < 20; i++)
		{
			if (!a[i])continue;
			while (p&&a[i])
			{
				cout << i * 5 + 6 - a[i] << " ";
				p--, a[i]--;
			}
		}
		cout << endl;
	}
	else
	{
		for (int i = pos * 5 + 6 - a[pos], j = 0; j < p; i++, j++)
			cout << i << " ";
		a[pos] -= p;
		cout << endl;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 20; i++)
		a[i] = 5;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		solve(b[i]);
	return 0;
}