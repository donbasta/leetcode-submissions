class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        vector<vector<int>> cnt(26, vector<int>(26));
        for (auto s : words) {
            cnt[s[0] - 'a'][s[1] - 'a']++;
        }
        bool odd = false;
        for (int i = 0; i < 26; i++) {
            for (int j = i; j < 26; j++) {
                if (i == j) {
                    ans += 2 * (cnt[i][j] / 2);
                    if (cnt[i][j] & 1) odd = true;
                } else {
                    ans += 2 * min(cnt[i][j], cnt[j][i]);
                }
            }
        }
        ans += odd;
        return ans * 2;
    }
};