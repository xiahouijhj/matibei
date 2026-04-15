#include<bits/stdc++.h>
using namespace std;

struct Node {
    int id, val;
    // 自定义比较规则：val 小的优先级高 (用于优先队列)
    bool operator<(const Node& other) const {
        return val > other.val; // 注意：priority_queue 默认是大顶堆，这里写 > 变小顶堆
    }
};

void testAdapters() {
    cout << "\n=== Adapters & Heaps ===" << endl;

    // 1. 默认大顶堆
    priority_queue<int> maxHeap;
    
    // 2. 标准小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10); minHeap.push(5); minHeap.push(20);
    cout << "Min heap top: " << minHeap.top() << " (Expected: 5)" << endl;
    minHeap.pop();
    cout << "Min heap top: " << minHeap.top() << " (Expected: 10)" << endl;

    // 3. 结构体堆
    priority_queue<Node> nodeHeap;
    nodeHeap.push({1, 100});
    nodeHeap.push({2, 50});
    cout << "Node heap top id: " << nodeHeap.top().id << " (Expected: 2)" << endl;
}
int main()
{
    testAdapters();
}
