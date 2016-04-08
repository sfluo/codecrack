#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/**
 * Topologic Sort (DFS version)
 *	
 */

class Node {
public:
	int key;
	Node(int k) : key(k) {}
};

class Graph {
public:
	Graph(int n) : nodes{n, Node(0)} {}

	Graph(int n, vector<vector<int>> adj) {
		nodes = std::vector<Node>(n, Node(0));
		adjacency.resize(n);
		vector<bool> head = vector<bool>(n, true);
		for (auto e : adj) {
			adjacency[e[0]-1].push_back(e[1]-1);
			head[e[1]-1] = false;
		}
		int i = 0;
		for (auto h : head) 
			if (h) heads.push_back(i++);
	}

	template<int r, int c>
	Graph(int (&e)[r][c]) {
		nodes = std::vector<Node>(c, Node(0));
		adjacency.resize(c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (e[i][j] == 0)
					continue;
				adjacency[i].push_back(j);
			}
		}
		for (int j = 0; j < c; j++) {
			bool head = true;
			for (int i = 0; i < r; i++) {
				if (e[i][j] != 0) 
					head = false;
			}
			if (head) heads.push_back(j);
		}
	}
	~Graph() {}

	std::stack<int>	topSort()
	{
		std::stack<int>	ret;
		std::vector<int>	st (nodes.size(), 0);
		for (int i = 0; i < heads.size(); i++)
			dfs(heads[i], ret, st);
		return ret;
	}
	
private:
	void dfs(int root, std::stack<int>& ret, std::vector<int>& st)
	{
		st[root] = 1;
		for (int j = 0; j < adjacency[root].size(); j++)
			if (st[adjacency[root][j]] == 0)
				dfs(adjacency[root][j], ret, st);
		st[root] = 2;
		ret.push(root);
	}
	void printvec(std::vector<int>& st)
	{
		for (auto v : st) std::cout << " " << v;
		std::cout << std::endl;
	}
	
private:
	std::vector<Node>	nodes;
	std::vector<int>	heads;
	std::vector<std::vector<int>>	adjacency;
};


int main(int argc, char ** argv)
{
	vector<vector<int>> es = {{1,2}, {1,3}, {1,4}, {3,5}, {2,5}, {4,5}};
	Graph g(5, es);
	std::stack<int> ret = g.topSort();
	while (!ret.empty())
	{
		std::cout << " " << ret.top();
		ret.pop();
	}	
	std::cout << "\n";

	return 0;
}




