class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in(n);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) in[leftChild[i]]++;
            if (rightChild[i] != -1) in[rightChild[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] > 1) return false;
        }
        bool ans = true;
        vector<bool> vis(n);
        const function<void(int)> dfs = [&](int v) -> void {
            if (leftChild[v] != -1) {
                if (vis[leftChild[v]]) {
                    ans = false;
                    return;
                }
                vis[leftChild[v]] = true;
                dfs(leftChild[v]);
            }
            if (rightChild[v] != -1) {
                if (vis[rightChild[v]]) {
                    ans = false;
                    return;
                }
                vis[rightChild[v]] = true;
                dfs(rightChild[v]);
            }
        };
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                ans = true;
                vis[0] = true;
                dfs(0);
                if (ans == false) {
                    return false;
                }
                cnt++;
            }
        }
        if (cnt != 1) return false;
        return true;
    }
};