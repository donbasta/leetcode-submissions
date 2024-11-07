class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        int m = strs.size();
        int ans = 0;

        vector<pair<int, int>> itv;
        itv.emplace_back(0, m - 1);
        for (int i = 0; i < n; i++) {
            bool can = true;
            for (auto it : itv) {
                int r1 = it.first, r2 = it.second;
                for (int j = r1 + 1; j <= r2; j++) {
                    if (strs[j][i] < strs[j - 1][i]) {
                        can = false;
                        break;
                    }
                }
                if (!can) break;
            }
            if (!can) {
                ans++;
                continue;
            }
            vector<pair<int, int>> tmp;
            for (auto it : itv) {
                int r1 = it.first, r2 = it.second;
                int st = r1;
                for (int j = r1 + 1; j <= r2; j++) {
                    if (strs[j][i] > strs[j - 1][i]) {
                        tmp.emplace_back(st, j - 1);
                        st = j;
                    }
                }
                tmp.emplace_back(st, r2);
            }
            itv = tmp;
        }
    
        return ans;
    }
};