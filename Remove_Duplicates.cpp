#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int iCount = 0;

		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
			{
				iCount += 1;
			}
		}

		return nums.size() - iCount;
	}
};

class OptimalSolution :public Solution
{
public:
	int removeDuplicates(vector<int>& nums) {

	}
};

int main()
{
	return 0;
}