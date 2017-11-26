#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << n / 50 * 2 + n % 50 / 30 + n / 10 << endl;
	return 0;
}