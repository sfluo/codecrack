
#include <iostream>
#include <random>

using namespace std;

struct _node {
	int key;
	struct _node *left;
	struct _node *right;
};

typedef struct _node Node;

class Solution {
public:
	int getLargestPath(Node *root)
	{
		int depth = 0;
		if (root == nullptr) return 0; 
		return getLargestPath(root, depth);
	}
private:
	int getLargestPath(Node *root, int& depth)
	{
		if (root == 0) { depth = 0; return 0; }
		int dp_l = 0, dp_r = 0;
		int left = getLargestPath(root->left, dp_l);
		int right = getLargestPath(root->right, dp_r);
		depth = max(dp_l, dp_r) + 1;
		// either the longest path exists in left/right subtree
		// or the one includes this root, but get the longest
		return max(max(left, right), dp_l + dp_r + 1);
	}
};

class Testing {
public:
	// random generate subtree with:
	// 0 - no child; 1 - left child; 
	// 2 - right child; 3 - both 
	static Node *genBinaryTree(int& len, int& depth, int limit)
	{
		Node *root = new Node;
		root->key = 0;
		root->left = nullptr;
		root->right = nullptr;
		
		if (limit < 1) { len = 0; depth = 0; return root; }

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 3); 
		int guard = dis(gen);
		int left = 0, right = 0;
		int d_l = 0, d_r = 0;
		root->key = guard; // just for record
		if (guard & 1)
			root->left = genBinaryTree(left, d_l, limit-1);
		if (guard & 2)
			root->right = genBinaryTree(right, d_r, limit-1);
		len = max(max(left, right), d_l + d_r + 1);
		depth = max(d_l, d_r) + 1;
		return root;	
	}
};

int main(int argc, char** argv)
{
	Solution s;
	int gd_len = 0, gd_depth = 0;
	Node *root = Testing::genBinaryTree(gd_len, gd_depth, 100); 
	int path = s.getLargestPath(root);
	if (path == gd_len) cout << "Correct!" << endl;
	cout << "Largest Path: " << path << endl;
	
	return 0;
}
