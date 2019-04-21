#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, w, s, c, key[1001];


struct Teacher//定义教师结构体
{
	int key;//钥匙编号
	int time;//使用钥匙时间
	int flag;//设置标识符
};

bool cmp(const Teacher& t1, const Teacher& t2)//自定义比较函数
{
	if (t1.time != t2.time)//使用时间少的先还
	{
		return t1.time < t2.time;
	}
	else if (t1.flag != t2.flag)//先归还后取出
	{
		return t1.flag > t2.flag;
	}
	else//钥匙编号从小到大归还
	{
		return t1.key < t2.key;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	vector<Teacher> v;//定义结构体向量
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		key[i] = i;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> w >> s >> c;
		Teacher t;
		t.key = w;
		t.time = s;
		t.flag = 0;//设置取出标识
		v.push_back(t);
		t.key = w;
		t.time = s + c;
		t.flag = 1;//设置归还标识
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);//自定义排序
	for (int i = 0; i < v.size(); i++)
	{
		Teacher t = v[i];
		if (!t.flag)//取出钥匙
		{
			for (int j = 1; j <= n; j++)
			{
				if (key[j] == t.key)
				{
					key[j] = 0;
					break;
				}
			}
		}
		else//归还钥匙
		{
			for (int j = 1; j <= n; j++)
			{
				if (key[j] == 0)//找到空挂钩
				{
					key[j] = t.key;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << key[i] << " ";
	}
	cout << endl;
	return 0;
}