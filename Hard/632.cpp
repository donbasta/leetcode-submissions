class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int, int>> hehe;
        for (int i = 0; i < k; i++) {
            for (auto e : nums[i]) {
                hehe.emplace_back(e, i);
            }
        }
        sort(hehe.begin(), hehe.end());
        int ri = 0;
        int len = hehe.size();
        vector<int> cnt(k);
        cnt[hehe[0].second]++;
        const function<bool(void)> check = [&]() -> bool {
            for (int i = 0; i < k; i++) {
                if (cnt[i] == 0) return false;
            }
            return true;
        };
        int mn = hehe.back().first - hehe[0].first;
        vector<int> ans = {hehe[0].first, hehe.back().first};
        for (int i = 0; i < len; i++) {
            while (ri < len && !check()) {
                ri++;
                if (ri < len) cnt[hehe[ri].second]++;
            }
            if (ri == len) break;
            if (hehe[ri].first - hehe[i].first < mn) {
                mn = hehe[ri].first - hehe[i].first;
                ans[0] = hehe[i].first;
                ans[1] = hehe[ri].first;
            }
            cnt[hehe[i].second]--;
        }
        return ans;
    }
};