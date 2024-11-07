class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ret;
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].emplace_back(i);
        }
        sort(tasks.begin(), tasks.end(), [&](vector<int>& A, vector<int>& B) -> bool {
            return A[0] < B[0];
        });
        using ll = long long;
        ll cur_time = 0;
        int ptr = 0;
        set<pair<int, int>> se;
        while (ptr < n || !se.empty()) {
            while (ptr < n && tasks[ptr][0] <= cur_time) {
                se.emplace(tasks[ptr][1], tasks[ptr][2]);
                ptr++;
            }
            if (se.empty()) {
                int nx = tasks[ptr][0];
                while (ptr < n && tasks[ptr][0] == nx) {
                    se.emplace(tasks[ptr][1], tasks[ptr][2]);
                    ptr++;
                }
                cur_time = nx;
            }
            pair<int, int> take = *se.begin();
            se.erase(se.begin());
            cur_time += take.first;
            ret.push_back(take.second);
        }
        return ret;
    }
};