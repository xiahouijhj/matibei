#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 500005;
const int LOGN = 20; // 2^20 > 500,000

vector<int> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];

// 预处理：DFS 计算深度和 2^0 级祖先
void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p; // 2^0 级祖先就是父节点
    
    // 动态规划预处理倍增表：u 的 2^i 祖先等于 (u 的 2^(i-1) 祖先) 的 2^(i-1) 祖先
    for (int i = 1; i < LOGN; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
}

// 查询 LCA
int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    // 1. 先跳到同一深度（利用位运算加速）
    for (int i = LOGN - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    
    if (u == v) return u;
    
    // 2. 一起向上跳，直到父亲节点相同
    for (int i = LOGN - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    return up[u][0]; // 返回它们的父节点
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, root;
    cin >> n >> m >> root;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(root, root, 0);

    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << "\n";
    }

    return 0;
}
