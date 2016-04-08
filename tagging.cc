
#include <iostream>
#include <queue>

using namespace std;

/*
 * given a list of tagged range, 
 *  	i.e. [10, 53, 0] where tag 0 has a range [10, 53)
 * 		Note: the same tag may have several interleaving ranges
 * find the range covered by all tags of a query
 */
class Solution {
public:
	queue<int> seekTags(vector<vector<int>>& tags, vector<int>& query)
	{
		queue<int>	myq;
		if (query.size() == 0) return myq;
		for (int i = 0; i < tags.size(); i++) {
			if (query[0] == tags[i][2]) {
				myq.push(tags[i][0]);
				myq.push(tags[i][1]);
			}
		}
		if (query.size() == 1) return myq;
		myq.push(-1); // canary

		for (int t = 1; t < query.size(); t++) {
			queue<int> copy = myq;
			for (int i = 0; i < tags.size(); i++) {
				if (tags[i][2] != t) continue;
				/* if tags sorted, tags[i][1] < low to stop (optimize) */
				queue<int> tmpq = copy;
				while (!tmpq.empty() && tmpq.front() != -1 && tmpq.size() > 2) {
					int low = tmpq.front(); tmpq.pop();
					int high = tmpq.front(); tmpq.pop();
					if (tags[i][0] < high && tags[i][1] > low) {
						myq.push(max(low, tags[i][0]));	
						myq.push(min(high, tags[i][1]));
					}
				}
			}
			while (myq.front() != -1) myq.pop();
			myq.pop(); // pop canary
			if (myq.size() == 0) break; // no more interset 
			myq.push(-1);
		}
		return myq;
	}
	void printQueue(queue<int>& ans) {
		cout << "Ranges:\n";
		while (!ans.empty() && ans.front() != -1) {
			cout << "[" << ans.front();
			ans.pop();
			cout << ", " << ans.front();
			ans.pop();
			cout << ")\n";
		}
		ans.pop();
	}
};

int main(int argc, char ** argv)
{
	Solution s;
	vector<vector<int>> tags = {{10, 53, 0}, {23, 72, 1}, {100, 125, 0}, {92, 110, 1}};
	vector<int>	query = {0, 1};
	queue<int> ans = s.seekTags(tags, query);
	s.printQueue(ans);
	return 0;
}
