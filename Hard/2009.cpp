class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> lmao = nums;
        sort(lmao.begin(), lmao.end());
        lmao.resize(unique(lmao.begin(), lmao.end()) - lmao.begin());
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < lmao.size(); i++) {
            int mn = lmao[i];
            int mx = lmao[i] + n - 1;
            int t = upper_bound(lmao.begin(), lmao.end(), mx) - lmao.begin();
            int filled = t - i;
            ans = min(ans, n - filled);
        }
        return ans;
    }
};