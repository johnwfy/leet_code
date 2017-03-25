#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> tp(digits), ret;

		// ���λ��1
		tp[tp.size() - 1]++;

		// �ӵ�λ����λ���ÿһλ�Ƿ���Ҫ��λ
		for (int i = tp.size() - 1; i > 0; i--)
		{
			if (tp[i] >= 10) 
			{
				tp[i] %= 10;
				tp[i - 1] ++;
			}
			else break;
		}

		// �����λ��Ҫ��λ����Ҫ������vectorͷ����һ��Ԫ��
		if (tp[0] >= 10) 
		{
			ret.push_back(1);
			tp[0] %= 10;
		}

		// �Ӹ�λ����λ���ν�ÿһ��Ԫ�ش���ret
		for (int i = 0; i != (int)tp.size(); ++i)
		{
			ret.push_back(tp[i]);
		}

		return ret;
	}
};

class OptimalSolution :public Solution
{
public:

	}
};

int main(int argc, char *argv[])
{
	vector<int> vecTest;
	//vecTest.push_back(-2);
	//vecTest.push_back(1);
	//vecTest.push_back(-3);
	//vecTest.push_back(1);
	//vecTest.push_back(1);
	//vecTest.push_back(1);
	//vecTest.push_back(1);

	for (int i = 1; i < argc; ++i)
	{
		vecTest.push_back(atoi(argv[i]));
	}

	Solution solution;
	cout << solution.plusOne(vecTest) << endl;

	for (vector<int>::iterator it = vecTest.begin(); it != vecTest.end(); ++it)
	{
		//cout << *it << endl;
	}

	//OptimalSolution optSolution;
	//int A[] = { 1,1 };
	//cout << sizeof(A) / sizeof(int) << endl;
	//optSolution.removeDuplicates(A, sizeof(A)/sizeof(int));
	//cout << sizeof(A) / sizeof(int) << endl;
	//for (int i = 0;i < sizeof(A) / sizeof(int);++i)
	//{
	//	//cout << A[i] << endl;
	//}

	return 0;
}