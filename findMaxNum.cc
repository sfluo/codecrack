#include <vector>
#include <iostream>
#include <limits>

using namespace std;

/*
 *Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.
 */

class Solution {
public:
#if 0
    vector<int> maxNumber(vector<int>& A, vector<int>& B, int k) {
        vector<int> ans;
        int a = -1, b = -1;
        int m = A.size(), n = B.size();
        for (int c = 0; c < k; c++) {
            int ea = m-1, eb = n-1;
            while (ea > a || eb > b) {
                int i = findMaxDigit(A, a+1, ea, B, b+1, eb); //inclusive
                if (i < m) {
					cout << m - (i + 1) + n - (b + 1) << " " << k - (c+1) << endl;
                    if (m - (i + 1) + n - (b + 1) >= k - (c+1)) { // found in A
                        a = i; 
						ans.push_back(A[i]); 
						break;
                    } 
					ea = i - 1;
                } else {
                    i -= m;
                    if (m - (a + 1) + n - (i + 1) >= k - (c+1)) { // found in B
                        b = i; 
						ans.push_back(B[i]);
						break;
                    }
                    eb = i - 1;
                }
            }
        }
		return ans;
    }
#endif
    vector<int> maxNumber(vector<int>& A, int sa, int ea, vector<int>& B, int sb, int eb, int k) {
	{
	}
    vector<int> maxNumber(vector<int>& A, int sb, vector<int>& B, int k) {
        vector<int> ans;
        int a = -1, b = -1;
        int m = A.size(), n = B.size();
        for (int c = 0; c < k; c++) {
            int ea = m-1, eb = n-1;
            while (ea > a || eb > b) {
                int i = findMaxDigit(A, a+1, ea);
                int j = findMaxDigit(B, b+1, eb);
				if (A[i] > B[j]) {
					if (m - (i + 1) + n - (b + 1) >= k - (c+1)) { // found in A
						a = i; 
						ans.push_back(A[i]); 
					} else  {
						ea = i - 1; // this pos after does not have enough digits
					}
				} else if (A[i] < B[j]);
                    if ((m - (a + 1) + n - (j + 1) >= k - (c+1))) { // found in B
                        b = j; 
						ans.push_back(B[j]);
					} else {
						eb = j - 1;
					}
                } else {  // found both in A and B

				}
            }
        }
		return ans;
    }
    int findMaxDigit(vector<int>& A, int sa, int ea, vector<int>& B, int sb, int eb)
    {
        int max = INT_MIN, pos = -1;
        for (int i = sa; i <= ea; i++) {
            if (A[i] > max) {
                max = A[i];
				pos = i;
			}
        }
        for (int i = sb; i <= eb; i++) {
            if (B[i] > max) {
                max = B[i];
				pos = i + A.size();
			}
        }
        return pos;
    }
};

int main(int argc, char* argv[])
{
	Solution s;
	//int a[] = {3,4, 6, 5};
	//int b[] = {9, 1, 2, 5, 8, 3};
	int a[] = {3, 9, 5};
	int b[] = {8, 9, 9};
	vector<int> A(&a[0], &a[0]+3);
	vector<int> B(&b[0], &b[0]+3);

	int k = 5;

	cout << "Searching ... " << endl;
	vector<int> ans = s.maxNumber(A, B, k);
	
	cout << "Printing ... " << endl;
	for (auto a:ans)
		std::cout << a << std::endl;
}
