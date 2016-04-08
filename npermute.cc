
#include <iostream>
#include <vector>

using namespace std;

/**
 * Permuation:
 * 	all permutations of lenght n for a given array
 */

class Solution {
public:
	vector<vector<int>> npermute(vector<int>& arr, int n)
	{
		vector<vector<int>> ans = {{}};
		
		for (int i = 0; i < n; i++) {
			vector<vector<int>> tmp;	
			for (auto v : ans) {
				for(int j = 0; j < arr.size(); j++) {
					vector<int> t = v;
					t.push_back(arr[j]);
					tmp.push_back(t);
				}
			}
			ans.swap(tmp);
		}
		return ans;
	}
};

int main(int argc, char** argv)
{
	vector<int> a = {4, 2, 3, 1};
	Solution s;
	vector<vector<int>> res = s.npermute(a, 3);
	for (auto v : res) {
		for (auto a : v) 
			std::cout << a << " ";
		std::cout << "\n";
	}
	return 0;
}
