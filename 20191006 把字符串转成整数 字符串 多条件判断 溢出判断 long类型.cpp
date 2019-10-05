// Topic link：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// 同步CSDN

class Solution {
public:
	int StrToInt(string str) {
		long long ret = 0;        // OJ中注意 整数越界问题不要采用int赋值，在此long即可
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '-' || str[i] == '+')
			{
				if (str[i] == '-')
					flag = -1;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				ret *= 10;
				ret += str[i] - '0';
			}
			else
			{
				return 0;
			}

		}
		// 若将ret设置为int型，则该判断无效，编译器内部进行优化
		if (((ret >= 2147483649) && (flag == -1)) || (ret * flag >= 2147483648))
			return 0;
		else
			return ret * flag;
	}
};
