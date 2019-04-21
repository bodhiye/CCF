#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> Pair;//�Զ���pair����

int a[1001];
map<int, int> m;
map<int, int>::iterator it;
vector<Pair> v;

bool cmp(const Pair& x, const Pair& y)//�Զ���ȽϺ�����ʹ��const���Ա��⴫�����û���ָ�뱻������޸�
{
	return (x.second > y.second || x.second == y.second && x.first < y.first);//�������
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

	//��map�еļ�ֵ�����ݴ�������vector�У�Ȼ������vector��sort��������
	for (it = m.begin(); it != m.end(); ++it)
	{
		v.push_back(make_pair(it->first, it->second));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i != v.size(); ++i)//�������vector
	{
		cout << v[i].first << " " << v[i].second << endl;
	}
	//���������򵥱���orz
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