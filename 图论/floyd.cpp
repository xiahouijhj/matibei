#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 根据题目边权累加和调整，防止加法溢出
int d[505][505];    // 邻接矩阵存储最短距离

/**
 * Floyd-Warshall 算法
 * @param n 点数
 */
void floyd(int n) {
    // 核心：枚举中间点 k
    for (int k = 1; k <= n; ++k) {
        // 枚举起点 i
        for (int i = 1; i <= n; ++i) {
            // 枚举终点 j
            for (int j = 1; j <= n; ++j) {
                // 如果经过点 k 能让 i 到 j 的距离更短，则更新
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
}
