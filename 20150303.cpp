#include <iostream>

using namespace std;
int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//����ÿ���µ�����

int leapyear(int y)//�ж��Ƿ�Ϊ����
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int a, b, c, y1, y2, sum = 0, days, weekday, d;
	cin >> a >> b >> c >> y1 >> y2;

	for (int i = 1850; i < y1; i++)//�����1850�굽y1��ǰһ���������
	{
		sum += 365 + leapyear(i);
	}

	for (int y = y1; y <= y2; y++)
	{
		days = sum;

		if (leapyear(y))
		{
			day[2] = 29;//�������29
		}
		else
		{
			day[2] = 28;//ƽ�����28
		}

		for (int i = 1; i < a; i++)
		{
			days += day[i];//�����1850�굽y��a��ǰһ���������
		}
		int weekday = (days + 1) % 7 + 1;//����y��a��1�յ�������

		if (c < weekday)//����y���a�µ�b������c�ǵ��µļ���
		{
			d = (b - 1) * 7 + c + 8 - weekday;
		}
		else
		{
			d = (b - 1) * 7 + c - weekday + 1;
		}

		if (d > day[a])
		{
			printf("none\n");//�����a�µ�b������c��������
		}
		else
		{
			printf("%d/%02d/%02d\n", y, a, d);
		}
		sum += 365 + leapyear(y);//�����1850�굽y+1��ǰһ���������
	}
	return 0;
}