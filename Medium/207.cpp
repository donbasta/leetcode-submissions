class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> from(numCourses);
        
        for (int i = 0; i < n; i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            from[b].emplace_back(a);
        }
        
        vector<int> col(numCourses);
        const function<bool(int)> dfs = [&](int v) -> bool {
            col[v] = 1;
            bool ans = true;
            for (auto c : from[v]) {
                if (col[c] == 1) return false;
                else if (col[c] == 0) {
                    ans &= dfs(c);
                }
            }
            col[v] = 2;
            return ans;
        };
        
        bool ans = true;
        for (int i = 0; i < numCourses; i++) {
            if (col[i] == 0) {
                ans &= dfs(i);
            }
        }
        return ans;
    }
};