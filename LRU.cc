
#include <queue>
#include <vector>
#include <iostream>

struct _LRUIdx
{
	int time;
	int idx;
	int key;

	_LRUIdx(int t, int i, int k) : time(t), idx(i), key(k) {}
};
typedef struct _LRUIdx LRUIdx;

class LRUComparator
{
public:
	bool operator()(const LRUIdx& r1, const LRUIdx& r2)
	{
		return r1.time > r2.time;
	}
};

int main(int argc, char** argv)
{
	std::priority_queue<LRUIdx, std::vector<LRUIdx>, LRUComparator>	lq;
	
	LRUIdx first(1, 1, 2);
	LRUIdx second(2, 2, 3);
	LRUIdx third(3, 4, 1);

	lq.push(first);
	lq.push(second);
	lq.push(third);
	
	while (!lq.empty())
	{
		LRUIdx t = lq.top();
		std::cout << "idx=" << t.idx << ", key=" <<  t.key << std::endl;
		lq.pop();
	}

	return 0;
}
