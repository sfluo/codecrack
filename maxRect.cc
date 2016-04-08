
#include <queue>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/** 
 * Max Area
 * 	find the max area filled with 1 in a 0-1 matrix
 */
class Solution {
public:
	int maximalRectangleDp(vector<vector<char>>& matrix) {
		const int row = matrix.size();
		if (0 == row) return 0;
		const int col = matrix[0].size();
		vector<vector<int>> ones(row, vector<int>(col+1, 0));
		for (int i = 0; i < row; i++) 
			for (int j = 0; j < col; j++)
				if (matrix[i][j] == '1') 
					ones[i][j] = 1 + (i > 0 ? ones[i-1][j] : 0);

		int i = 0, max_a = 0;
		for (int i; i < row; i++) {
			stack<int> stk;
			vector<int> cur = ones[i];
			int idx = 0;
			while (idx < cur.size()) {
				if (stk.empty() || cur[idx] >= cur[stk.top()]) {
					stk.push(idx++);
				} else {
					int h = stk.top();
					stk.pop();
					max_a = max(max_a, cur[h] *(stk.empty() ? idx : idx - stk.top() - 1));
				}
			}
		}
		return max_a;
	}
	void printStack(stack<int> st) {
		while (!st.empty()) {
			std::cout << " " << st.top();
			st.pop();
		}
		std::cout << std::endl;
	}
};

int main(int argc, char **argv)
{
	//string input[] = {"11111111", "11111110", "11111110", "11111000", "01111000"};
	string input[] = {"11001011", "10110110", "10111110", "11111000", "01111000"};
	vector<vector<char>> matrix(5);
	for (int i = 0; i < 5; i++)
		matrix[i].assign(input[i].begin(), input[i].end());
	std::cout << "initialized" << std::endl;

	Solution s;
	int area = s.maximalRectangleDp(matrix) ;
	std::cout << " Max Area = " << area << "." << std::endl;
	
	return 0;
}
