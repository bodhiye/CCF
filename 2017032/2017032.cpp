#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<int>::iterator it;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	while (m--)
	{
		int p, q;
		cin >> p >> q;
		for (it = v.begin(); it != v.end(); it++)
		{
			if (*it == p)
			{
				it = v.erase(it);
				//v.erase(it);
				v.insert(it + q, p);
				break;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}