#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 构建 next 数组
 * next[i] 表示从 0 到 i 的子串中，相等的前后缀的最大长度
 */
void getNext(vector<int>& next, const string& p) {
    int n = p.size();
    int j = 0; // j 指向前缀末尾位置，同时也代表当前最长相等前后缀长度
    next[0] = 0; // 第一个字符的前后缀长度必为 0

    for (int i = 1; i < n; i++) {
        // 如果字符不匹配，j 依次回退到前一位置的 next 值
        while (j > 0 && p[i] != p[j]) {
            j = next[j - 1];
        }
        // 如果字符匹配，j 向后移
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
}

/**
 * KMP 匹配过程
 * s: 主串 (Text)
 * p: 模式串 (Pattern)
 */
void kmpSearch(const string& s, const string& p) {
    int m = s.size();
    int n = p.size();
    if (n == 0) return;

    vector<int> next(n);
    getNext(next, p); // 预处理模式串

    int j = 0; // 模式串的指针
    for (int i = 0; i < m; i++) { // i 为主串指针
        // 当不匹配时，利用 next 数组跳过不必要的匹配
        while (j > 0 && s[i] != p[j]) {
            j = next[j - 1];
        }
        // 匹配成功，模式串指针后移
        if (s[i] == p[j]) {
            j++;
        }
        // 完全匹配成功
        if (j == n) {
            cout << "Pattern found at index: " << i - n + 1 << endl;
            // 继续匹配下一个（可能重叠）的匹配点
            j = next[j - 1];
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Text:    " << text << endl;
    cout << "Pattern: " << pattern << endl;
    
    kmpSearch(text, pattern);

    return 0;
}
