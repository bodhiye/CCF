#include<iostream>
inline bool is_true(int &x, int &y) {
	int c = y - 3500;
	int c1 = y - x;
	int sum;
	if (c >= 80000)
		sum = (c - 80000)*0.45 + 22495;
	else if (c >= 55000)
		sum = (c - 55000)*0.35 + 13745;
	else if (c >= 35000)
		sum = (c - 35000)*0.30 + 7745;
	else if (c >= 9000)
		sum = (c - 9000)*0.25 + 1245;
	else if (c >= 4500)
		sum = (c - 4500)*0.20 + 345;
	else if (c >= 1500)
		sum = (c - 1500) *0.10 + 45;
	else sum = c*0.03;
	if (sum == c1)
	{
		return true;
	}
	else
		return false;
}
using  namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, a, num, S;
	cin >> T;
	if (T <= 3500)
		S = T;
	else {
		a = T / 100 + 1;
		do {
			S = 100 * a;
			++a;
		} while (!is_true(T, S));
	}
	cout << S << endl;
	return 0;
}