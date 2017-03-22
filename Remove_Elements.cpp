#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())
			return 0;

		vector<int>::iterator it = nums.begin();
		for (; it != nums.end(); )
		{
			if (*it == val)
			{
				nums.erase(it);
			}
			else
			{
				++it;
			}
		}

		return nums.size();
	}
};

class OptimalSolution :public Solution
{
public:
	int removeElement(int A[], int n, int elem) {
		int begin = 0;
		for (int i = 0;i<n;i++) if (A[i] != elem) A[begin++] = A[i];
		return begin;
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
	cout << solution.removeDuplicates(vecTest) << endl;

	for (vector<int>::iterator it = vecTest.begin();it != vecTest.end();++it)
	{
		cout << *it << endl;
	}

	return 0;
}