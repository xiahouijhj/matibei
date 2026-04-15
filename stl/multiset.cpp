#include<bits/stdc++.h>

using namespace std;

int main() {
    // 1. 初始化
    multiset<int> ms = {3, 1, 4, 1, 5, 9, 1}; // 允许重复的 1

    // 2. 插入元素
    ms.insert(3); 
    // 此时集合内部：1, 1, 1, 3, 3, 4, 5, 9 (自动排序)

    // 3. 查找与计数
    cout << "Count of 1: " << ms.count(1) << endl; // 输出 3

    // 4. 删除操作 (注意陷阱！)
    // 方式 A: 删除所有值为 1 的元素
    // ms.erase(1); 

    // 方式 B: 只删除其中一个 1 (通过迭代器删除)
    auto it = ms.find(1);
    if (it != ms.end()) {
        ms.erase(it); 
    }

    // 5. 遍历
    cout << "Current elements: ";
    for (int x : ms) cout << x << " "; 
    cout << endl;

    multiset<int> mss = {10, 20, 20, 20, 30, 40};

    // lower_bound: 返回第一个 >= 20 的迭代器
    auto it1 = mss.lower_bound(20);
    
    // upper_bound: 返回第一个 > 20 的迭代器
    auto it2 = mss.upper_bound(20);

    cout<<*it1<<' '<<*it2<<endl;
    return 0;
}
