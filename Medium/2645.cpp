class Solution {
public:
    int addMinimum(string word) {
        int n = word.length();

        vector<int> DP(n, -1);
        function<int(int)> dp = [&](int idx) -> int {
            if (idx < 0) return 0;
            if (DP[idx] != -1) return DP[idx];
            int ret;
            if (word[idx] == 'a') ret = 2 + dp(idx - 1);
            else if (word[idx] == 'b') {
                if (idx > 0 && word[idx - 1] == 'a') ret = 1 + dp(idx - 2);
                else ret = 2 + dp(idx - 1);
            } else if (word[idx] == 'c') {
                if (idx > 1 && word[idx - 1] == 'b' && word[idx - 2] == 'a') ret = dp(idx - 3);
                else if (idx > 0 && (word[idx - 1] == 'a' || word[idx - 1] == 'b')) ret = 1 + dp(idx - 2);
                else ret = 2 + dp(idx - 1);
            }
            return DP[idx] = ret;
        };

        return dp(n - 1);
    }
};