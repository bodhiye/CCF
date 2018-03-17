#include <iostream>

using namespace std;

//二维数组定义成全局变量或者加static可以防止栈溢出，当然也可以使用new，全局变量存放在静态存储区中，而局部变量存放在栈中
int a[1001][1001], b[1001][1001];
int rotate(int a[][1001], int n, int m);//定义矩阵旋转函数

int main()
{
	std::ios::sync_with_stdio(false);//加快使用cin时的数据读入速度，基本上能和scanf读入速度一样快
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

int rotate(int a[][1001], int n, int m)//不能使用二级指针来传二维数组参数，只能用二维数组来传参数，且列的值不能为空
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(b + i) + j) = *(*(a + j) + m - i - 1);//使用地址计算来表示数组元素
		}
	}
	return **b;//用二级指针返回二维数组
}