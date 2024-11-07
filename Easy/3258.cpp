class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> cnt(2);
                for (int t = i; t <= j; t++) {
                    cnt[s[t] - '0']++;
                }
                if (cnt[0] <= k || cnt[1] <= k) ans++;
            }
        }
        return ans;
    }
};