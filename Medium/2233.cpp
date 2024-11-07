class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        multiset<int> se;
        for (auto e : nums) se.insert(e);
        for (int i = 0; i < k; i++) {
            auto now = *se.begin();
            se.erase(se.find(now));
            se.insert(++now);
        }
        int ans = 1;
        const int MOD = 1e9 + 7;
        for (auto e : se) {
            ans = (1ll * ans * e) % MOD;
        }
        return ans;
    }
};