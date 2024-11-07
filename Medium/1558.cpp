class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int mx = 0;
        for (auto e : nums) {
            int tmp = 0;
            while (e) {
                ans += (e & 1);
                tmp++;
                e >>= 1;
            }
            mx = max(tmp, mx);
        }
        return ans + max(0, (mx - 1));
    }
};