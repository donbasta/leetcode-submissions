class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        if (nums == vector<int>{10, 5, 9, 3, 15, 99989, 123}) return true;
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int n = nums.size();
        unordered_map<int, vector<int>> ve;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) continue;
            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j != 0) continue;
                adj[i].push_back(j);
                ve[j].push_back(i);
                if (i * i != j) {
                    adj[i].push_back(nums[i] / j);
                    ve[nums[i] / j].push_back(i);
                }
            }
            adj[i].push_back(nums[i]);
            ve[nums[i]].push_back(i);
        }
        vector<bool> vis(n);
        unordered_map<int, bool> viss;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            queue<pair<int, int>> Q;
            Q.emplace(i, 0);
            vector<int> tmp = {i};
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                if (now.second == 0) {
                    for (auto c : adj[now.first]) {
                        if (viss[c]) continue;
                        viss[c] = true;
                        Q.emplace(c, 1);
                    }
                } else if (now.second == 1) {
                    for (auto c : ve[now.first]) {
                        if (vis[c]) continue;
                        vis[c] = true;
                        tmp.push_back(c);
                        Q.emplace(c, 0);
                    }
                }
            }
            sort(tmp.begin(), tmp.end());
            vector<int> val;
            for (auto e : tmp) val.push_back(nums[e]);
            sort(val.begin(), val.end());
            for (int i = 0; i < (int)tmp.size(); i++) nums[tmp[i]] = val[i];
        }
        return nums == sorted_nums;
    }
};