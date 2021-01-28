#include <iostream>
#include <vector>
using namespace std;

int findRoot(vector<int> parentArr, int x) {
    // if 'x' has its own root, then we should find root vertext by recursive. 
    if (parentArr[x] == x) return x;
	 return parentArr[x] = findRoot(parentArr, parentArr[x]);
}

//  assumed that the number is high in priority order in a fast order.
void unionOperation(vector<int>& parentArr, int lhs, int rhs) {
    lhs = findRoot(parentArr, lhs), rhs = findRoot(parentArr, rhs);
    parentArr[rhs] = lhs;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k;   
    cin >> n >> k;
    
    // Make every vertex in different set.
    vector<int> parentArr(n + 1);
    for (int i = 1; i <= n; ++i) parentArr[i] = i;
    for (int i = 0; i < k; ++i) {
        char op;
        int s, e;
        cin >> op >> s >> e;
        if (op == 'u') unionOperation(parentArr, s, e);
        else if (op == 't') 
            (parentArr[s] == parentArr[e]) ? cout << "true\n" : cout << "false\n";
    }
}
