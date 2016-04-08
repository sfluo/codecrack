
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

/**
 * Max Number:
 *	find the max number by concatenate all numbers from a given array
 *
 */
class Solution {
public:
	class vecComp {
	public:
		bool operator()(vector<int>& v1, vector<int>& v2) {
			if (v1.size() == 0) return !(v2.size() == 0);
			if (v2.size() == 0) return (v1.size() == 0);
			int i = v1.size()-1, j = v2.size()-1;
			while (i >=0 && j >= 0) {
				if (v1[i] > v2[j]) return false;
				if (v1[i] < v2[j]) return true;
				if (v1[i] == v2[j]) {
					if (i > 0) i--; 
					if (j > 0) j--;
				}
			}
			return true;
		}
		void printVector(vector<int>& a)
		{
			std::cout <<"[";
			for (auto i : a) std::cout << " " << i;
			std::cout << "]\n";
		}
	};
	int maxNum(vector<int> nums)
	{
		int ndigits = 0, ans = 0;
		priority_queue<vector<int>, vector<vector<int>>, vecComp> digits;

		for (int num : nums) {
			vector<int> d;	
			while (num != 0) {
				d.push_back(num%10);
				num /= 10;
				ndigits++;
			}
			digits.push(d);
		}
		int p = pow(10, ndigits - 1); // overflow!!!!
		while (!digits.empty()) {
			vector<int> d = digits.top();	
			digits.pop();
			for (int i = d.size() - 1; i >= 0; i--) {
				ans += p * d[i];	
				p /= 10;
			}
		}
		return ans;
	}
};

int main(int argc, char** argv)
{
	//vector<int> nums = {917, 918, 9};
	vector<int> nums = {1, 112, 113, 51};
	Solution s;
	std::cout << "res=" << s.maxNum(nums) << std::endl;
	return 0;
}
