class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.length();
        vector<vector<int>> child(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] >= 0) {
                child[parent[i]].push_back(i);
            } 
        }
        int ans = 1;
        const function<int(int)> dfs = [&](int v) -> int {
            int ret = 1;
            vector<int> tmp;
            for (auto c : child[v]) {  
                int k = dfs(c);
                if (s[c] != s[v]) {
                    ret = max(ret, k + 1);
                    tmp.push_back(k);
                }
            }
            if (!tmp.empty()) {
                sort(tmp.begin(), tmp.end(), greater<>());
                if (tmp.size() >= 2) {
                    ans = max(ans, 1 + tmp[0] + tmp[1]);
                } else if (tmp.size() == 1) {
                    ans = max(ans, 1 + tmp[0]);
                }
            }
            return ret;
        };
        dfs(0);
        return ans;
    }
};