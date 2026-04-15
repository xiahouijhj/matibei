#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void testSequenceContainers() {
    cout << "=== Vector & Deque Advanced ===" << endl;

    // 1. Vector 预分配内存 (避免频繁扩容导致的 O(n) 拷贝)
    vector<int> v;
    v.reserve(100); // 提前分配空间，capacity 变为 100，但 size 仍为 0
    
    // 2. 各种初始化
    vector<int> v1(5, -1);      // [-1, -1, -1, -1, -1]
    vector<int> v2 = {1, 2, 3}; // 初始化列表
    
    // 3. 插入与删除 (注意：这些操作在中间位置是 O(n))
    v2.insert(v2.begin() + 1, 99); // 在索引 1 处插入 99 -> {1, 99, 2, 3}
    v2.erase(v2.begin() + 2);      // 删除索引 2 的元素 -> {1, 99, 3}

    // 4. 二维动态数组初始化
    vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3行4列全0

    // 5. Deque 的双端特性
    deque<int> dq = {10, 20};
    dq.push_front(5);  // {5, 10, 20}
    dq.push_back(25);  // {5, 10, 20, 25}
    
    cout << "Vector v2 back: " << v2.back() << " (Expected: 3) " << endl;
    cout << "Deque front: " << dq.front() << " (Expected: 5)" << endl;
}
int main()
{
    testSequenceContainers();
}
