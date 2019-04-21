#include <iostream>

using namespace std;

int a[18][10], b[4][4];

int main()
{
	std::ios::sync_with_stdio(false);
	int s;
	bool flag = false;
	for (int i = 16; i <= 18; i++)
		for (int j = 1; j <= 10; j++)
			a[i][j] = 1;
	for (int i = 1; i <= 15; i++)
		for (int j = 1; j <= 10; j++)
			cin >> a[i][j];
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			cin >> b[i][j];
	cin >> s;
	for (int k = 0; k < 15 && !flag; k++)
		for (int i = 1; i <= 4 && !flag; i++)
			for (int j = 1; j <= 4; j++)
				if ((b[i][j] && a[k + i + 1][s + j - 1]))
				{
					for (int m = 1; m <= 4; m++)
						for (int n = 1; n <= 4; n++)
							a[k + m][s + n - 1] = a[k + m][s + n - 1] | b[m][n];
					flag = true;
					break;
				}
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 10; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}