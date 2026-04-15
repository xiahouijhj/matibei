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
}
