#include <iostream>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
int a[N], temp[N];
ll ans = 0; // 记录逆序对数量

void merge_sort(int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    // 合并阶段
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            // a[i] > a[j]，此时 a[i...mid] 与 a[j] 都构成逆序对
            ans += (mid - i + 1); 
            temp[k++] = a[j++];
        }
    }

    // 处理剩余元素
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    // 复制回原数组
    for (i = l, k = 0; i <= r; i++, k++) a[i] = temp[k];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    merge_sort(0, n - 1);
    
    cout << ans << endl;
    return 0;
}
