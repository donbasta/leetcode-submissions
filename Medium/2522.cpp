class Solution {
public:
    int minimumPartition(string s, int k) {
        string sk = to_string(k);
        int n = sk.length();
        int m = s.length();

        if (n == 1) {
            for (auto c : s) {
                if ((c - '0') > k) {
                    return -1;
                }
            }
            return m;
        }

        vector<int> DP(m, -1);
        const function<int(int)> dp = [&](int start_idx) -> int {
            if (start_idx >= m) return 0;
            if (DP[start_idx] != -1) return DP[start_idx];
            int tmp = dp(start_idx + n - 1) + 1;
            if (start_idx + n - 1 < m && stoi(s.substr(start_idx, n)) <= k) {
                tmp = min(tmp, dp(start_idx + n) + 1);
            }
            return DP[start_idx] = tmp;
        };

        return dp(0);
    }
};