#include <iostream>

using namespace std;

//��ά���鶨���ȫ�ֱ������߼�static���Է�ֹջ�������ȻҲ����ʹ��new��ȫ�ֱ�������ھ�̬�洢���У����ֲ����������ջ��
int a[1001][1001], b[1001][1001];
int rotate(int a[][1001], int n, int m);//���������ת����

int main()
{
	std::ios::sync_with_stdio(false);//�ӿ�ʹ��cinʱ�����ݶ����ٶȣ��������ܺ�scanf�����ٶ�һ����
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> *(*(a + i) + j);
		}
	}
	rotate(a, n, m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(b + i) + j) << " ";
		}
		cout << endl;
	}
	return 0;
}

int rotate(int a[][1001], int n, int m)//����ʹ�ö���ָ��������ά���������ֻ���ö�ά�����������������е�ֵ����Ϊ��
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(b + i) + j) = *(*(a + j) + m - i - 1);//ʹ�õ�ַ��������ʾ����Ԫ��
		}
	}
	return **b;//�ö���ָ�뷵�ض�ά����
}