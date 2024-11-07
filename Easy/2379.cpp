class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int> pw(n);
        for (int i = 0; i < n; i++) {
            pw[i] = (i ? pw[i - 1] : 0) + (blocks[i] == 'W');
        }
        int ans = n;
        for (int i = 0; i <= n - k; i++) {
            ans = min(ans, pw[i + k - 1] - (i ? pw[i - 1] : 0));
        }
        return ans;
    }
};