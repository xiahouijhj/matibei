#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//取模加法
inline int add_mod(int a, int b, int m) {
    return (a % m + b % m) % m;
}
//取模减法
inline int sub_mod(int a, int b, int m) {
    return (a - b % m + m) % m;
}
//取模乘法
ll mul_mod(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % m;
        a = (a + a) % m;
        b /= 2;
    }
    return res;
}
//乘法逆元，费马小定理在mod意义下，a^(mod-2)=a^(-1) 
ll power_mod(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
