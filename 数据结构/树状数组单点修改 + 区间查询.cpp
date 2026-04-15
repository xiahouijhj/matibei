#include <iostream>
#include <vector>

using namespace std;

class BIT_PointUpdate {
    vector<int> tree;
    int n;
    int lowbit(int x) { return x & -x; }

public:
    BIT_PointUpdate(int size) : n(size), tree(size + 1, 0) {}

    void update(int i, int val) {
        for (; i <= n; i += lowbit(i)) tree[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= lowbit(i)) sum += tree[i];
        return sum;
    }

    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    cout << "--- Testing: Point Update, Range Query ---" << endl;
    BIT_PointUpdate bit(5);
    bit.update(1, 1);
    bit.update(2, 2);
    bit.update(3, 3); // 数组变为 [1, 2, 3, 0, 0]
    
    cout << "Sum [1, 3]: " << bit.queryRange(1, 3) << " (Expected: 6)" << endl;
    bit.update(2, 10); // 2号位置加10，数组变为 [1, 12, 3, 0, 0]
    cout << "Sum [1, 3] after update: " << bit.queryRange(1, 3) << " (Expected: 16)" << endl;
    return 0;
}
