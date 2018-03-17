#include <iostream>

using namespace std;

int a[1001], b[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
		a[i] = b[a[i]];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}