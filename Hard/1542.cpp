class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length();
        int B[n + 1];
        B[0] = 0;
        for (int i = 0; i < n; i++) {
            B[i + 1] = B[i] ^ (1 << (s[i] - '0'));
        }
        unordered_map<int, int> R;
        for (int i = 0; i <= n; i++) R[B[i]] = i;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int ki = B[i - 1];
            int best = R[ki];
            for (int j = 0; j < 10; j++) {
                int tmp = ki ^ (1 << j);
                if (R.count(tmp)) {
                    best = max(best, R[tmp]);
                }
            }
            ans = max(ans, best - i + 1);
        }
        return ans;
    }
};