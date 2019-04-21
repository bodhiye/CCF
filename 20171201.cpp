#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int b[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i<n - 1; i++)
	{
		b[i] = a[i + 1] - a[i];
	}
	sort(b, b + n - 1);
	cout << b[0] << endl;
	return 0;
}