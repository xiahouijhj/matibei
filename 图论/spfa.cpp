#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to, weight;
};

/**
 * SPFA 模板
 * @param n 点数
 * @param start 起点
 * @param adj 邻接表
 */
void spfa(int n, int start, const vector<vector<Edge>>& adj) {
    vector<long long> dist(n + 1, INF);
    vector<bool> in_queue(n + 1, false); // 标记点是否在队列中，避免重复入队
    queue<int> q;

    dist[start] = 0;
    q.push(start);
    in_queue[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false; // 出队后重置标记

        for (auto& edge : adj[u]) {
            int v = edge.to;
            if (dist[u] + edge.weight < dist[v]) {
                dist[v] = dist[u] + edge.weight;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    // 输出结果...
}
