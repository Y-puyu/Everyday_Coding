// https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// OJ�������ڵ�����ת��
// ��Ŀ����
// ������������ڣ���������һ��ĵڼ��졣��
// ��ϸ������
// ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
// �ӿ���Ƽ�˵����

/*****************************************************************************
Description   : ����ת��
Input Param   : year �������
			   Month �����·�
			   Day ������

Output Param  :
Return Value  : �ɹ�����0��ʧ�ܷ���-1���磺���ݴ���
*****************************************************************************/
//public static int iConverDateToDay(int year, int month, int day)
//{
//	/* ������ʵ�ֹ��ܣ��������������������*/
//	return 0;
//}

/*****************************************************************************
Description   :
Input Param   :

Output Param  :
Return Value  : �ɹ�:����outDay��������ĵڼ���;
										  ʧ��:����-1
*****************************************************************************/
//public static int getOutDay()
//{
//	return 0;
//}
//
//��������:
//�������У��ֱ����꣬�£���
//
//������� :
//�ɹ�:����outDay��������ĵڼ���;
//ʧ��:���� - 1
//
//	ʾ��1
//	����
//	����
//	2012
//
//	12
//
//	31
//	���
//	����
//	366

// �����������࣬������Ȼ��OJ�϶�����Ҫ��ô���ӣ����п�����Ϊ����������OJ�����Կ졢׼���ݲ���������
// OJţ�ͻ�Ϊ��������ѵ���������ڵ�����ת��

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

// ���Ա���ѭ�������·������ۼƵ�array�����ڣ�ÿ�β���Ҫ�ټ����ۼ�������

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