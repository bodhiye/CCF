#include <iostream>

using namespace std;
int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//定义每个月的天数

int leapyear(int y)//判断是否为闰年
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int a, b, c, y1, y2, sum = 0, days, weekday, d;
	cin >> a >> b >> c >> y1 >> y2;

	for (int i = 1850; i < y1; i++)//计算从1850年到y1年前一天的总天数
	{
		sum += 365 + leapyear(i);
	}

	for (int y = y1; y <= y2; y++)
	{
		days = sum;

		if (leapyear(y))
		{
			day[2] = 29;//闰年二月29
		}
		else
		{
			day[2] = 28;//平年二月28
		}

		for (int i = 1; i < a; i++)
		{
			days += day[i];//计算从1850年到y年a月前一天的总天数
		}
		int weekday = (days + 1) % 7 + 1;//计算y年a月1日的星期数

		if (c < weekday)//计算y年的a月第b个星期c是当月的几号
		{
			d = (b - 1) * 7 + c + 8 - weekday;
		}
		else
		{
			d = (b - 1) * 7 + c - weekday + 1;
		}

		if (d > day[a])
		{
			printf("none\n");//该年的a月第b个星期c并不存在
		}
		else
		{
			printf("%d/%02d/%02d\n", y, a, d);
		}
		sum += 365 + leapyear(y);//计算从1850年到y+1年前一天的总天数
	}
	return 0;
}