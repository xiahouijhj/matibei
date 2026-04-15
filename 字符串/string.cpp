#include <iostream>
#include <string>   // 核心头文件
#include <vector>

using namespace std;

int main() {
    // --- 1. 声明与初始化 ---
    string s1 = "Hello";            // 字面量
    string s2("World");             // 构造函数
    string s3(5, '!');              // 重复字符: "!!!!!"
    string full = s1 + " " + s2;    // 拼接: "Hello World"

    cout << "--- Initialization ---" << endl;
    cout << "Full string: " << full << endl;


    // --- 2. 访问与遍历 ---
    cout << "\n--- Access ---" << endl;
    cout << "First char: " << full[0] << endl;       // 下标访问
    cout << "Safe access: " << full.at(1) << endl;   // at()访问（带越界检查）
    
    cout << "Traversal: ";
    for (char c : full) {                            // 范围 for 循环
        cout << "[" << c << "]";
    }
    cout << endl;


    // --- 3. 修改操作 ---
    cout << "\n--- Modification ---" << endl;
    full.append(" :)");             // 后缀添加
    full.insert(5, ",");            // 在索引5处插入逗号: "Hello, World :)"
    full.replace(7, 5, "C++");      // 从索引7开始的5个字符替换为"C++": "Hello, C++ :)"
    full.erase(full.size() - 3);    // 删除最后3个字符
    
    cout << "Modified: " << full << endl;


    // --- 4. 查找与子串 ---
    cout << "\n--- Search & Substring ---" << endl;
    string sentence = "The quick brown fox jumps over the lazy dog";
    size_t found = sentence.find("fox"); // 查找子串

    if (found != string::npos) {
        cout << "'fox' found at index: " << found << endl;
    }

    // substr(起始位置, 长度)
    string sub = sentence.substr(10, 5); // 提取 "brown"
    cout << "Substring (10, 5): " << sub << endl;


    // --- 5. 容量与状态 ---
    cout << "\n--- Capacity ---" << endl;
    cout << "Length: " << sentence.length() << endl; // 长度
    cout << "Is empty? " << (sentence.empty() ? "Yes" : "No") << endl;
    
    sentence.resize(10); // 截断或填充到10个字符
    cout << "Resized to 10: " << sentence << endl;


    // --- 6. 数值转换 (C++11) ---
    cout << "\n--- Conversion ---" << endl;
    string numStr = "123.45";
    double val = stod(numStr);      // String TO Double
    int iVal = stoi("42");          // String TO Integer
    
    string backToStr = to_string(val + 10); // 数字转 String
    cout << "String to double: " << val << endl;
    cout << "Back to string: " << backToStr << endl;


    // --- 7. 输入流技巧 ---
    cout << "\n--- Input Tips ---" << endl;
    cout << "Type something (with spaces): ";
    string input;
    // 注意：cin >> input 会在空格处停止
    // getline 可以读取整行
    getline(cin, input); 
    cout << "You entered: " << input << endl;

    return 0;
}
