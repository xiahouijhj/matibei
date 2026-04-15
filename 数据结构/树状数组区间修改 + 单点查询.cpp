#include <iostream>
#include <vector>

using namespace std;

class BIT_RangeUpdate_PointQuery {
    vector<int> tree;
    int n;
    int lowbit(int x) { return x & -x; }

    void add(int i, int val) {
        for (; i <= n; i += lowbit(i)) tree[i] += val;
    }

public:
    BIT_RangeUpdate_PointQuery(int size) : n(size), tree(size + 1, 0) {}

    // 区间修改：[l, r] 增加 val
    void updateRange(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    // 单点查询
    int queryPoint(int i) {
        int res = 0;
        for (; i > 0; i -= lowbit(i)) res += tree[i];
        return res;
    }
};

int main() {
    cout << "\n--- Testing: Range Update, Point Query ---" << endl;
    BIT_RangeUpdate_PointQuery bit(5);
    // 初始 [0, 0, 0, 0, 0]
    bit.updateRange(2, 4, 5); // [0, 5, 5, 5, 0]
    cout << "Point 1: " << bit.queryPoint(1) << " (Expected: 0)" << endl;
    cout << "Point 3: " << bit.queryPoint(3) << " (Expected: 5)" << endl;
    
    bit.updateRange(3, 5, 2); // [0, 5, 7, 7, 2]
    cout << "Point 3 after update: " << bit.queryPoint(3) << " (Expected: 7)" << endl;
    cout << "Point 5 after update: " << bit.queryPoint(5) << " (Expected: 2)" << endl;
    return 0;
}
