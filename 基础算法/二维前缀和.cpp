#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N], s[N][N];

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // 1. 读入并预处理前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            // 核心公式：上 + 左 - 左上 + 当前值
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    // 2. 处理查询
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 核心公式：右下 - 两个侧边矩形 + 重复扣除的左上矩形
        int res = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        cout << res << endl;
    }

    return 0;
}
