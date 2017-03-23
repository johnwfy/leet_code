#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;

		vector<int>::iterator it = nums.begin();
		for (int i = 0; i < nums.size(); ++i, ++it)
		{
			if (target == nums[i])
			{
				return i;
			}
			else if (target < nums[i])
			{
				nums.insert(it, target);
				return i;
			}
			else
			{
				if (i == nums.size() - 1)
				{
					nums.push_back(target);
					return nums.size() - 1;
				}
			}
		}

		return 0;
	}
};

class OptimalSolution :public Solution
{
public:

};

int main(int argc, char *argv[])
{
	vector<int> vecTest;
	vecTest.push_back(0);
	vecTest.push_back(1);
	vecTest.push_back(2);
	/*vecTest.push_back(1);
	vecTest.push_back(1);
	vecTest.push_back(1);
	vecTest.push_back(1);*/

	Solution solution;
	cout << solution.searchInsert(vecTest, atoi(argv[1])) << endl;

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