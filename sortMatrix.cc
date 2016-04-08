
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * Sort Matrix: 
 * 	1. every row is in a non-descending order
 * 	2. every column is in a non-descending order
 */
class Solution {
public:
	vector<vector<int>> sortMatrix(vector<vector<int>>& M)
	{
		if (M.size() == 0) return vector<vector<int>>();
		// skip if one dimension array
		if (M.size() < 2 || M[0].size() < 2) return M;
		int rows = M.size(), cols = M[0].size();
		vector<int>	arr = vector<int>(rows * cols, 0);
		for (int i = 0; i < rows; i++) {
			int k = i * cols;
			for (int j = 0; j < cols; j++)
				arr[k+j] = M[i][j];	
		}
		std::sort(arr.begin(), arr.end());
		M[0][0] = arr[0];
		rearrange(M, rows, cols, arr, 1, 1);
		return M;
	}

	void rearrange(vector<vector<int>>& M, int rows, int cols, 
		vector<int>& arr, int r, int c)
	{
		int k = 0;
		std::queue<int>	reserv;
		if (c == cols - 1 && r > c) k = r * cols;
		else if (r == rows - 1 && c > r) k = rows * c;
		else k = r * c; 

		M[r][c] = arr[(c + 1) * r + c];
		// fill all (r-1) elems in j-th column
		if (c >= r) {
			for (int i = 0; i < r; i++) {
				while (k < (c + 1) * r + c && M[i][c-1] == arr[k]) { reserv.push(k); k++; }
				//if ((c + r - k) < (r - i - 1))  // enough left
				M[i][c] = arr[k++];
			}
		}
		// fill all (c-1) elems in i-th row
		if (c <= r) {
			for (int j = 0; j < c; j++) { 
				if (!reserv.empty()) { 
					M[r][j] = reserv.front(); 
					reserv.pop();
				} else M[r][j] = arr[k++];
			}
		}
		if (r == rows - 1 && c == cols - 1) return; // reach the end - we are done;
		if (r < rows - 1) r += 1; // only advance if more row
		if (c < cols - 1) c += 1; // only advance if more col
		rearrange(M, rows, cols, arr, r, c);		
	}
	void printMatrix(vector<vector<int>>& m)
	{
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m[0].size(); j++)
				std::cout << " " << m[i][j];
			std::cout << "\n";
		}
	}
	void printArray(vector<int>& a)
	{
		for (int i = 0; i < a.size(); i++)
			std::cout << " " << a[i];
		std::cout << "\n";
	}
};

int main(int argc, char** argv)
{
	Solution s;
	//vector<vector<int>> matrix = {{1,3,5}, {3, 2,4}};
	vector<vector<int>> matrix = {{6,3,5}, {3, 2,4}, {7, 1, 8}};
	s.sortMatrix(matrix);
	s.printMatrix(matrix);
	return 0;
}
