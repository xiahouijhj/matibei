#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 边结构体：存储起点、终点和权值
struct Edge {
    int u, v, w;
    // 重载小于号，用于 sort 按权值升序排列
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

const int MAXN = 200005; // 根据点数范围调整
const int MAXM = 500005; // 根据边数范围调整

int p[MAXN]; // 并查集数组

// 并查集核心：查找祖先节点 + 路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 1. 按边权从小到大排序 O(M log M)
    sort(edges.begin(), edges.end());

    // 2. 初始化并查集
    for (int i = 1; i <= n; ++i) p[i] = i;

    long long res = 0; // 存储 MST 权值之和，注意 long long
    int cnt = 0;       // 记录加入的边数

    // 3. 贪心选择边
    for (int i = 0; i < m; ++i) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        // 如果不在同一个连通分量中，则合并（不形成环）
        if (a != b) {
            p[a] = b;
            res += edges[i].w;
            cnt++;
        }
    }

    // 4. 连通性判断：MST 必须有 n-1 条边
    if (cnt < n - 1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
