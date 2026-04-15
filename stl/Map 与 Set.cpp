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
    //删除为2的数
    s.erase(2);
    //用迭代器删除
    auto it=s.find(8);//查找数值为8的迭代器
    if(it!=s.end())
    {
        s.erase(it);
    }
    for(auto i=s.begin();i!=s.end();i++)//遍历s
    {
        cout<<(*i)<<' ';
    }
    cout<<endl;
    // 3. Map 的 [] 与 insert 区别
    map<int, string> mp;
    mp[1] = "Apple";       // 若 key 不存在则创建，存在则修改
    mp.insert({2, "Pear"}); // 若 key 已存在则插入失败
    cout<<"mp[1]: "<<mp[1]<<endl;
    cout<<"mp[2]: "<<mp[2]<<endl;
    
    for(auto i=mp.begin();i!=mp.end();i++)//遍历mp顺序为key值从小到大
    {
        cout<<(*i).first<<' '<<(*i).second<<endl;
    }
    // 4. lower_bound/upper_bound (有序容器的灵魂)
    // 返回第一个 >= 5 的位置
    auto itt = s.lower_bound(5);
    cout << "Lower bound of 5: " << *itt << endl;

    // 5. 自定义排序 (降序)
    set<int, greater<int>> descSet = {1, 5, 3}; // {5, 3, 1}
    cout << "Desc set first: " << *descSet.begin() << endl;
    
    cout<<endl;
}
int main()
{
    testAssociativeContainers();
}
