class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        multiset<int> se;
        int ans = 0;
        for (auto e : nums) se.insert(e), ans += e;
        while (k--) {
            int sm = *se.begin();
            se.erase(se.begin());
            se.insert(-sm);
            ans -= sm * 2;
        }
        return ans;
    }
};