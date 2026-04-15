#include <iostream>
#include <vector>

using namespace std;

class BIT_RangeUpdate_RangeQuery {
    vector<long long> t1, t2;
    int n;
    int lowbit(int x) { return x & -x; }

    void add(vector<long long>& t, int i, long long val) {
        for (; i <= n; i += lowbit(i)) t[i] += val;
    }

    long long ask(vector<long long>& t, int i) {
        long long res = 0;
        for (; i > 0; i -= lowbit(i)) res += t[i];
        return res;
    }

public:
    BIT_RangeUpdate_RangeQuery(int size) : n(size), t1(size + 1, 0), t2(size + 1, 0) {}

    void updateRange(int l, int r, long long val) {
        add(t1, l, val);
        add(t1, r + 1, -val);
        add(t2, l, val * l);
        add(t2, r + 1, -val * (r + 1));
    }

    long long queryPrefix(int i) {
        return (i + 1) * ask(t1, i) - ask(t2, i);
    }

    long long queryRange(int l, int r) {
        return queryPrefix(r) - queryPrefix(l - 1);
    }
};

int main() {
    cout << "\n--- Testing: Range Update, Range Query ---" << endl;
    BIT_RangeUpdate_RangeQuery bit(10);
    // 初始全 0
    bit.updateRange(1, 5, 2); // [1, 5] 设为 2，总和应为 10
    cout << "Sum [1, 5]: " << bit.queryRange(1, 5) << " (Expected: 10)" << endl;
    
    bit.updateRange(4, 6, 3); // 索引 4,5 原本是 2，现在加 3 变成 5；索引 6 原本 0 变 3
    // 数组现在类似: [2, 2, 2, 5, 5, 3, 0...]
    // Sum [4, 6] = 5 + 5 + 3 = 13
    cout << "Sum [4, 6]: " << bit.queryRange(4, 6) << " (Expected: 13)" << endl;
    return 0;
}
