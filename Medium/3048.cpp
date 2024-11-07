class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        set<int> se;
        int L = -1, R = m;
        for (int i = 0; i < m; i++) {
            se.insert(changeIndices[i]);
            if (se.size() == n) {
                L = i + 1;
                break;
            }
        }
        if (L == -1) return -1;
        int ans = -1;
        while (L <= R) {
            int M = (L + R) >> 1;
            vector<bool> ve(n + 1);
            queue<pair<int, int>> Q;
            for (int i = M - 1; i >= 0; i--) {
                if (!ve[changeIndices[i]]) {
                    if (nums[changeIndices[i] - 1] > 0) {
                        Q.emplace(nums[changeIndices[i] - 1], changeIndices[i]);
                    }
                    ve[changeIndices[i]] = true;
                } else {
                    if (!Q.empty()) {
                        auto now = Q.front();
                        Q.pop();
                        if (now.first > 1) Q.emplace(now.first - 1, now.second);
                    }
                }
            }
            if (Q.empty()) {
                ans = M;
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        return ans;
    }
};