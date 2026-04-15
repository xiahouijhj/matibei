#include <bits/stdc++.h>
using namespace std;

const int MAXW = 10005; // 根据题目要求调整
int dp[MAXW];

void solve() {
    int N, W;
    if (!(cin >> N >> W)) return;

    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; ++i) cin >> w[i] >> v[i];

    // 初始化：如果不要求恰好装满，全设为 0
    memset(dp, 0, sizeof(dp));

    // 如果要求恰好装满，则：
    // memset(dp, -0x3f, sizeof(dp));
    // dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = W; j >= w[i]; --j) {
            // 状态转移：选或不选当前物品
            if (dp[j - w[i]] != -0x3f3f3f3f) { // 仅当要求“恰好装满”时需此判断
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    // 输出结果
    // 若不要求恰好装满：直接输出 dp[W] 
    //（实际上此时 dp[W] 是所有 dp[0...W] 的最大值）
    cout << *max_element(dp, dp + W + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
