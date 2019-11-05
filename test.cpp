// https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// OJ计算日期到天数转换
// 题目描述
// 根据输入的日期，计算是这一年的第几天。。
// 详细描述：
// 输入某年某月某日，判断这一天是这一年的第几天？。
// 接口设计及说明：

/*****************************************************************************
Description   : 数据转换
Input Param   : year 输入年份
			   Month 输入月份
			   Day 输入天

Output Param  :
Return Value  : 成功返回0，失败返回-1（如：数据错误）
*****************************************************************************/
//public static int iConverDateToDay(int year, int month, int day)
//{
//	/* 在这里实现功能，将结果填入输入数组中*/
//	return 0;
//}

/*****************************************************************************
Description   :
Input Param   :

Output Param  :
Return Value  : 成功:返回outDay输出计算后的第几天;
										  失败:返回-1
*****************************************************************************/
//public static int getOutDay()
//{
//	return 0;
//}
//
//输入描述:
//输入三行，分别是年，月，日
//
//输出描述 :
//成功:返回outDay输出计算后的第几天;
//失败:返回 - 1
//
//	示例1
//	输入
//	复制
//	2012
//
//	12
//
//	31
//	输出
//	复制
//	366

// 很类似日期类，不过既然是OJ肯定不需要那么复杂，很有可能作为笔试题线上OJ，所以快、准、狠才是王道！
// OJ牛客华为机试在线训练计算日期到天数转换

#include <iostream>
using namespace std;
int main() {
	int array[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day) {
		sum = 0;
		for (int i = 0; i < month - 1; i++) {
			sum += array[i];
		}
		sum += day;
		if (month > 2) {
			if ((year % 4 == 0 && year % 100) || (year % 400 == 0)) {
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}

// 可以避免循环，将月份天数累计到array数组内，每次不需要再计算累计天数：

#include <iostream>
using namespace std;
int main() {
	int array[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day) {
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2) {
			if ((year % 4 == 0 && year % 100) || (year % 400 == 0)) {
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}