class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(26), CNT(26);
        const function<bool(char)> low = [&](char c) -> bool {
            return c >= 'a' && c <= 'z';
        };
        for (auto c : s) {
            if (low(c)) cnt[c - 'a']++;
            else CNT[c - 'A']++;
        }
        int ans = 0;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            ans += 2 * (cnt[i] / 2);
            if (cnt[i] & 1) odd++;
            ans += 2 * (CNT[i] / 2);
            if (CNT[i] & 1) odd++;
        }
        ans += (odd >= 1);
        return ans;
    }
};