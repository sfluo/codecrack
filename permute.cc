#include <iostream>
#include <vector>

using namespace std;

/* 
 * Permutation:
 *	all permutations of a given array
 */
class Solution {
public:
	void printVector(vector<int>& t)
	{
		std::cout << "t: {";
		for (int j = 0; j < t.size();j++)
			std::cout << " " << t[j];
		std::cout << "}\n";
	}

	void printPerm(vector<vector<int>>& perm)
	{
		std::cout << "tmp: \n{";
		for (int i = 0; i < perm.size(); i++)
			printVector(perm[i]);
		std::cout << "}\n";
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret = {{}};
		for (int n : nums){
			vector<vector<int>> temp;
			for (auto x : ret){
				for (int i = 0; i <= x.size(); i++){
					vector<int> t = x;
					t.insert(t.begin() + i, n);
					printVector(t);
					temp.push_back(t);
					printPerm(temp);
				}
			}
			ret.swap(temp);
		}
		return ret;
	}
};

int main(int argc, char** argv)
{
	int ints[]  = {1, 2, 3};
	Solution s;
	vector<int> nums = vector<int>(ints, ints+3);
	vector<vector<int>> perm = s.permute(nums);
	//s.printPerm(perm);
	return 0; 
}
