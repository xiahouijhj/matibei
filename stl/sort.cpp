#include<bits/stdc++.h>
using namespace std;
struct Student {
    int id;
    string name;
    int score;
};//以成绩为标准排序
bool compareStudents(const Student &a, const Student &b) {
    return a.score > b.score; 
}//普通数组排序比较函数

int main()
{
    //普通数组排序
    Student arr[3] = {
        {1, "Alice", 85},
        {2, "Bob", 95},
        {3, "Charlie", 90}
    };

    // 排序：传入起始地址和结束地址
    sort(arr, arr + 3, compareStudents);

    for(int i = 0; i < 3; i++) {
        cout << arr[i].name << ": " << arr[i].score << endl;
    }

    //vector数组排序
    vector<Student> v = {
        {1, "Alice", 85},
        {2, "Bob", 95},
        {3, "Charlie", 90}
    };

    // 使用 Lambda 表达式：按分数升序排
    sort(v.begin(), v.end(), [](const Student &a, const Student &b) {
        return a.score < b.score; 
    });

    for(const auto &s : v) {
        cout << s.name << ": " << s.score << endl;
    }
    return 0;
}
