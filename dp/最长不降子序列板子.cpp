#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> g;
    for (int x : a) {
        if (g.empty() || x >= g.back()) {
            g.push_back(x);
        } else {
            // 找到第一个大于 x 的位置（因为是不降，所以用 upper_bound）
            // 如果是严格上升子序列，则用 lower_bound（找到第一个大于等于 x 的位置）
            auto it = upper_bound(g.begin(), g.end(), x);
            *it = x;
        }
    }

    cout << g.size() << endl;
    return 0;
}
