#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
int inv[N];
//费马小定理求逆元
ll quick_pow(ll a, ll k, ll m) {
    ll res = 1;
    a %= m;
    while (k) {
        if (k & 1) res = res * a % m;
        a = a * a % m;
        k >>= 1;
    }
    return res;
}
//exgcd求逆元
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll get_inv(ll a, ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    if (d != 1) return -1; // 无逆元
    return (x % m + m) % m; // 确保结果为正数
}
//线性求逆元
void precompute_inv(int n, int p) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        // 递推公式：inv[i] = (p - p/i) * inv[p%i] % p
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    }
}
int main()
{
    //求模1e9+7意义下1e3+10的乘法逆元
    int mod=1e9+7;
    int x=1e3+10;
    int a=quick_pow(x,mod-2,mod);//费马小定理
    int b=get_inv(x,mod);//exgcd求逆元
    precompute_inv(x,mod);//求1-x的逆元，线性求逆元
}
