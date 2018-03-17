#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> Pair;//自定义pair类型

int a[1001];
map<int, int> m;
map<int, int>::iterator it;
vector<Pair> v;

bool cmp(const Pair& x, const Pair& y)//自定义比较函数，使用const可以避免传入引用或者指针被意外的修改
{
	return (x.second > y.second || x.second == y.second && x.first < y.first);//排序规则
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;

	while (n--)
	{
		int i;
		cin >> i;
		++m[i];
	}

	//把map中的键值对数据存入向量vector中，然后利用vector的sort方法排序
	for (it = m.begin(); it != m.end(); ++it)
	{
		v.push_back(make_pair(it->first, it->second));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i != v.size(); ++i)//遍历输出vector
	{
		cout << v[i].first << " " << v[i].second << endl;
	}
	//方法二，简单暴力orz
	/*for (int i = 1000; i > 0; i--)
	{
		for (int j = 1; j <= 1000; j++)
		{
			if (a[j] == i)
			{
				cout << j << " " << a[j] << endl;
			}
		}
	}*/
	return 0;
}