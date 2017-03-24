#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int iSum, iMax = 0;
		int iCount = 0;
		int iSpMax = nums[0];
		for (int i = 0; i < nums.size(); ++i)
		{
			iSum += nums[i];
			if (iSum > 0)
			{
				if(iMax < iSum)
					iMax = iSum;
			}
			else
			{
				++iCount;
				iSum = 0;
			}

			if (iSpMax <= nums[i])
			{
				iSpMax = nums[i];
			}
		}

		return (iCount == nums.size() ? iSpMax : iMax);
	}
};

class OptimalSolution :public Solution
{
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0, min = 0, res = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum - min > res) res = sum - min;
			if (sum < min) min = sum;
		}
		return res;
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
	cout << solution.maxSubArray(vecTest) << endl;

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