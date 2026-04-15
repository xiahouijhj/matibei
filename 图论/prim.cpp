#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 使用 long long 防止权值累加溢出
typedef long long ll;
typedef pair<ll, int> PLI; // <距离树的距离, 点编号>

const ll INF = 1e18;
const int MAXN = 200005; // 根据题目要求调整点数范围

struct Edge {
    int to;
    int weight;
};

vector<Edge> adj[MAXN];
ll dist[MAXN];
bool vis[MAXN];
int n, m;

/**
 * 堆优化版 Prim
 * 时间复杂度: O(M log N)
 */
ll prim() {
    // 1. 初始化
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    
    // 小顶堆：优先弹出距离生成树最近的点
    priority_queue<PLI, vector<PLI>, greater<PLI>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    ll res = 0;
    int cnt = 0; // 记录加入生成树的点数

    while (!pq.empty()) {
        PLI top = pq.top();
        pq.pop();

        ll d = top.first;
        int u = top.second;

        // 如果该点已经加入生成树，跳过（过时信息）
        if (vis[u]) continue;

        // 2. 确定加入生成树
        vis[u] = true;
        res += d;
        cnt++;

        // 3. 遍历邻居，更新集合外点到集合的距离
        for (auto &edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (!vis[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }

    // 4. 连通性判断
    return (cnt == n) ? res : -1; // -1 表示不连通
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;

    // 读入 m 条边
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // Prim 处理无向图
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll ans = prim();

    if (ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;

    return 0;
}
