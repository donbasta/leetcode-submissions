class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) {
            cnt[e]++;
        }
        int sz = cnt.size();
        vector<int> unq;
        for (auto e : cnt) {
            unq.push_back(e.first);
        }

        vector<vector<int>> ans;
        const function<void(int, vector<int>&)> rec = [&](int idx, vector<int>& cur) -> void {
            if (idx == sz) {
                ans.push_back(cur);
                return;
            } 
            rec(idx + 1, cur);
            for (int i = 0; i < cnt[unq[idx]]; i++) {
                cur.push_back(unq[idx]);
                rec(idx + 1, cur);
            }
            for (int i = 0; i < cnt[unq[idx]]; i++) {
                cur.pop_back();
            }
        };

        vector<int> tmp;
        rec(0, tmp);
        return ans;
    }
};