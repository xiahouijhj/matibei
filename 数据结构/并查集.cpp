#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 使用数组实现并查集，MAXN 根据题目范围调整
const int MAXN = 200005;
int fa[MAXN];

// 查找函数：包含路径压缩优化
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]); // 路径压缩，将路径上的点全部指向祖先
}

// 合并函数
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        fa[rootX] = rootY; // 将一个集合的根指向另一个集合的根
    }
}

int main() {
    // 快速输入输出优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 初始化：每个元素的父节点最初都是它自己
    for (int i = 1; i <= n; ++i) fa[i] = i;

    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            // 合并操作
            unite(x, y);
        } else {
            // 查询操作
            if (find(x) == find(y)) {
                cout << "Y" << "\n";
            } else {
                cout << "N" << "\n";
            }
        }
    }

    return 0;
}
