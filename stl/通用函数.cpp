#include<bits/stdc++.h>
using namespace std;

int main()
{
    //以vector为例
    vector<int> a={1,2,3,4};
    //遍历stl
    for(auto it=a.begin();it!=a.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    //stl的大小
    int x=a.size();
    cout<<"vector的大小"<<' '<<x<<endl;
    //stl是否为空集
    if(a.empty())
    {
        cout<<"a为空集"<<endl;
    }
    else
    {
        cout<<"a不为空集"<<endl;
    }
    int target=2;
    // 返回第一个 >=2  的迭代器
    auto lb = lower_bound(a.begin(), a.end(), target);
    // 返回第一个 >2 的迭代器
    auto ub = upper_bound(a.begin(), a.end(), target);
    //注意：set和multiset还有map需要用内置lower_bound和upper_bound,例子如下
    set<int> s={1,2,3,4};
    // 返回第一个 >=2  的迭代器
    auto sa = s.lower_bound(target);
    // 返回第一个 >2 的迭代器
    auto sb = s.upper_bound(target);
}
