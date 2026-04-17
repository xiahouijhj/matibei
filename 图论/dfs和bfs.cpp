#include<bits/stdc++.h>
using namespace std;

void dfs(int u) {
    vis[u] = true; // 标记当前节点已访问
    
    // 1. 判断是否到达终点或满足更新答案的条件
    if (check(u)) {
        // 更新答案或输出结果
        return;
    }

    // 2. 遍历当前节点的所有相邻节点（或所有可能的下一步）
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) { // 如果目标节点未访问
            dfs(v);    // 继续向下搜索
        }
    }
}


void bfs(int start) {
    queue<int> q;
    
    q.push(start);      // 1. 将起点放入队列
    vis[start] = true;  // 2. 标记起点（注意：BFS一定要入队即标记）

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // 遍历所有邻接点
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;      // 标记
                dist[v] = dist[u] + 1; // 更新距离（如果需要）
                q.push(v);          // 入队
            }
        }
    }
}
