#include<bits/stdc++.h>
using namespace std;

void testAssociativeContainers() {
    cout << "\n=== Map & Set Advanced ===" << endl;

    // 1. Set 的自动排序与去重
    set<int> s = {5, 2, 8, 2}; // 自动变为 {2, 5, 8}
    
    // 2. 查找的高效写法
    if (s.find(5) != s.end()) {
        cout << "Found 5 in set" << endl;
    }

    // 3. Map 的 [] 与 insert 区别
    map<int, string> mp;
    mp[1] = "Apple";       // 若 key 不存在则创建，存在则修改
    mp.insert({2, "Pear"}); // 若 key 已存在则插入失败
    
    // 4. lower_bound/upper_bound (有序容器的灵魂)
    // 返回第一个 >= 5 的位置
    auto it = s.lower_bound(5);
    cout << "Lower bound of 5: " << *it << endl;

    // 5. 自定义排序 (降序)
    set<int, greater<int>> descSet = {1, 5, 3}; // {5, 3, 1}
    cout << "Desc set first: " << *descSet.begin() << endl;
}
int main()
{
    testAssociativeContainers();
}
