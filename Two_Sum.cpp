#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		cout << "call Solution's func" << endl;
		vector<int> vecTemp;
		vecTemp.clear();
		int index = 0;

		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (target > 0)
			{
				if (nums[i] > target)
					continue;

				index = findIndex(nums, i + 1, target - nums[i]);
				if (index != -1)
				{
					vecTemp.push_back(i);
					vecTemp.push_back(index);
					break;
				}
			}
			else
			{
				index = findIndex(nums, i + 1, target - nums[i]);
				if (index != -1)
				{
					vecTemp.push_back(i);
					vecTemp.push_back(index);
					break;
				}
			}
		}

		return vecTemp;
	}

	int findIndex(vector<int>& nums, int beIndex, int remainTarget)
	{
		for (int i = beIndex; i < nums.size(); ++i)
		{
			if (nums[i] == remainTarget)
				return i;
		}

		return -1;
	}
};

class OptimalSolution :public Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		cout << "call SubSolution's func" << endl;
		//Key is the number and value is its index in the vector.
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];

			//if numberToFind is found in map, return them
			if (hash.find(numberToFind) != hash.end()) {
				//+1 because indices are NOT zero based
				result.push_back(hash[numberToFind] + 1);
				result.push_back(i + 1);
				return result;
			}

			//number was not found. Put it in the map.
			hash[numbers[i]] = i;
		}
		return result;
	}

};


int main()
{
	vector<int> vecTest;
	vecTest.push_back(2);
	vecTest.push_back(3);
	vecTest.push_back(7);
	vecTest.push_back(9);
	vecTest.push_back(10);

	vector<int> vecReault;
	OptimalSolution subSolution;
	vecReault = subSolution.twoSum(vecTest, 9);

	for (int i = 0; i < vecReault.size(); ++i)
	{
		cout << vecReault[i] << endl;
	}

	return 0;
}
