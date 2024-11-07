class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        vector<int> cnt(26);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            int x = cnt[i] % 2;
            if (x == 0) ans += 2;
            else ans++;
        }
        return ans;
    }
};