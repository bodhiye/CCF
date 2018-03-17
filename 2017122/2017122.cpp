#include <iostream>
#include <queue>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n, k, num = 1;
	queue<int> q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		int head = q.front();
		q.pop();
		if (num % k != 0 && num % 10 != k)
		{
			q.push(head);
		}
		num++;
	}
	cout << q.front() << endl;
	return 0;
}