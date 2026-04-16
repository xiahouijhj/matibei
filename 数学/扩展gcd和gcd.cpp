#include<bits/stdc++.h>
using namespace std;
/**
 * @param a, b 输入的两个数
 * @param x, y 引用传递，用于返回 ax + by = gcd(a, b) 的一组解
 * @return 返回 a 和 b 的最大公约数
 */
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; 
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x); // 注意这里 y 和 x 的位置交换
    y -= (a / b) * x;
    return d;
}
//gcd求最大公约数
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
