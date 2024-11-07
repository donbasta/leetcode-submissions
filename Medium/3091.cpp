class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9;
        for (int i = 1; i <= k; i++) {
            int tmp = (i - 1) + ((k - 1) / i);
            ans = min(ans, tmp);
        }
        return ans;
    }
};