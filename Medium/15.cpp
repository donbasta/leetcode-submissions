class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> se;
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        vector<int> hehe = nums;
        sort(hehe.begin(), hehe.end());
        hehe.resize(unique(hehe.begin(), hehe.end()) - hehe.begin());
        int n = hehe.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int need = - (hehe[i] + hehe[j]);
                vector<int> tmp;
                if (i == j) {
                    if (cnt[hehe[i]] == 1) continue;
                    if (need == hehe[i]) {
                         if (cnt[need] >= 3) tmp = {need, hehe[i], hehe[j]};
                    } else {
                        if (cnt.find(need) != cnt.end()) tmp = {need, hehe[i], hehe[j]};
                    }
                } else if (i != j) {
                    if (need == hehe[i]) {
                        if (cnt[need] >= 2) tmp = {need, hehe[i], hehe[j]};
                    } else if (need == hehe[j]) {
                        if (cnt[need] >= 2) tmp = {need, hehe[i], hehe[j]};
                    } else {
                        if (cnt.find(need) != cnt.end()) tmp = {need, hehe[i], hehe[j]};
                    }
                }
                if (!tmp.empty()) {
                    sort(tmp.begin(), tmp.end());
                    se.insert(tmp);
                }
            }
        }
        vector<vector<int>> ans(se.begin(), se.end());
        return ans;
    }
};