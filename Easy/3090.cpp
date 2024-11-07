class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> cnt(26);
                for (int k = i; k <= j; k++) {
                    cnt[s[k] - 'a']++;
                }
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};