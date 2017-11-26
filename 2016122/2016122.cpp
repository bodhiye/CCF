#include <iostream>

using namespace std;

int s[] = { 3500,5000,8000,12500,38500,58500,83500 };
int t[] = { 0,45,345,1245,7745,13745,22495 };
float rate[] = { 0.03,0.1,0.2,0.25,0.3,0.35,0.45 };

int main()
{
	std::ios::sync_with_stdio(false);
	int T, i, S;
	cin >> T;
	for (i = 6; i >= 0; i--)
	{
		if (T > s[i] - t[i])
		{
			break;
		}
	}
	S = s[i] + (T - s[i] + t[i]) / (1 - rate[i]);
	cout << S << endl;
	return 0;
}