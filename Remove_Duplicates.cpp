#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int iCount = 0;
		int iSize = nums.size();
		vector<int>::iterator it = nums.begin();
		vector<int>::iterator itor = nums.begin();
		int i = 0;
		for (; it != nums.end(); )
		{
			if (i == (iSize - 1))
			{
				break;
			}

			itor = it;
			if (*it == *(++itor))
			{
				nums.erase(it);
				iCount += 1;
			}
			else
			{
				++it;
			}

			++i;
		}

		return iSize - iCount;
	}
};

class OptimalSolution :public Solution
{
public:
	int removeDuplicates(int A[], int n) {
		if (n < 2) return n;
		int id = 1;
		for (int i = 1; i < n; ++i)
			if (A[i] != A[i - 1]) 
				A[id++] = A[i];
		return id;
	}
};

int main()
{
	vector<int> vecTest;
	vecTest.push_back(1);
	vecTest.push_back(1);
	//vecTest.push_back(2);
	/*vecTest.push_back(1);
	vecTest.push_back(1);
	vecTest.push_back(1);
	vecTest.push_back(1);*/

	Solution solution;
	//cout << solution.removeDuplicates(vecTest) << endl;

	for (vector<int>::iterator it = vecTest.begin();it != vecTest.end();++it)
	{
		//cout << *it << endl;
	}

	OptimalSolution optSolution;
	int A[] = { 1,1 };
	cout << sizeof(A) / sizeof(int) << endl;
	optSolution.removeDuplicates(A, sizeof(A)/sizeof(int));
	cout << sizeof(A) / sizeof(int) << endl;
	for (int i = 0;i < sizeof(A) / sizeof(int);++i)
	{
		//cout << A[i] << endl;
	}

	return 0;
}