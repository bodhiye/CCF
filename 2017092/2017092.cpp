#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, w, s, c, key[1001];


struct Teacher//�����ʦ�ṹ��
{
	int key;//Կ�ױ��
	int time;//ʹ��Կ��ʱ��
	int flag;//���ñ�ʶ��
};

bool cmp(const Teacher& t1, const Teacher& t2)//�Զ���ȽϺ���
{
	if (t1.time != t2.time)//ʹ��ʱ���ٵ��Ȼ�
	{
		return t1.time < t2.time;
	}
	else if (t1.flag != t2.flag)//�ȹ黹��ȡ��
	{
		return t1.flag > t2.flag;
	}
	else//Կ�ױ�Ŵ�С����黹
	{
		return t1.key < t2.key;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	vector<Teacher> v;//����ṹ������
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
		t.flag = 0;//����ȡ����ʶ
		v.push_back(t);
		t.key = w;
		t.time = s + c;
		t.flag = 1;//���ù黹��ʶ
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);//�Զ�������
	for (int i = 0; i < v.size(); i++)
	{
		Teacher t = v[i];
		if (!t.flag)//ȡ��Կ��
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
		else//�黹Կ��
		{
			for (int j = 1; j <= n; j++)
			{
				if (key[j] == 0)//�ҵ��չҹ�
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