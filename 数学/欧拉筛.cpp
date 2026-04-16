#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005; // 根据题目需求修改范围
int prime[MAXN];      // 存储找到的质数
bool is_not_prime[MAXN]; // 标记是否为合数（false表示质数）
int cnt = 0;          // 质数计数器

void euler_sieve(int n) {
    is_not_prime[0] = is_not_prime[1] = true; // 0和1不是质数
    
    for (int i = 2; i <= n; i++) {
        if (!is_not_prime[i]) {
            prime[++cnt] = i; // i是质数，加入数组
        }
        
        // 核心：遍历已找到的质数
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            is_not_prime[i * prime[j]] = true; // 筛掉合数
            
            // 重要：精髓所在！
            // 如果 i 能被 prime[j] 整除，说明 i 的最小质因子也是 prime[j]
            // 那么 i * prime[j+1] 的最小质因子依然是 prime[j]，而不是 prime[j+1]
            // 为了保证“每个合数只被最小质因子筛一次”，这里必须跳出
            if (i % prime[j] == 0) break; 
        }
    }
}

int main() {
    int n;
    cin >> n;
    euler_sieve(n);
    for (int i = 1; i <= cnt; i++) {
        cout << prime[i] << " ";
    }
    return 0;
}
