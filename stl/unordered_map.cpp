#include <bits/stdc++.h>
using namespace std;

void testUnorderedContainers() {
    cout << "\n=== Unordered Containers (Hash Table) ===" << endl;

    // 平均复杂度 O(1)，最坏 O(n)
    unordered_map<string, int> ump;
    ump["C++"] = 1983;
    ump["Java"] = 1995;
    ump["Python"] = 1991;

    ump["apple"]++; 
    
    cout << "Apple count: " << ump["apple"] << endl;
    cout << "Apple count: " << ump["C++"] << endl;
    cout << "Apple count: " << ump["Java"] << endl;
    cout << "Apple count: " << ump["Python"] << endl;
}
int main()
{
    testUnorderedContainers();
}
