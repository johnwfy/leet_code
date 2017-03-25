#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> tp(digits), ret;

		// 最低位加1
		tp[tp.size() - 1]++;

		// 从低位到高位检查每一位是否需要进位
		for (int i = tp.size() - 1; i > 0; i--)
		{
			if (tp[i] >= 10) 
			{
				tp[i] %= 10;
				tp[i - 1] ++;
			}
			else break;
		}

		// 若最高位需要进位，需要额外在vector头增加一个元素
		if (tp[0] >= 10) 
		{
			ret.push_back(1);
			tp[0] %= 10;
		}

		// 从高位到低位依次将每一个元素存入ret
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