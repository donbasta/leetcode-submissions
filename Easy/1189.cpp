class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26);
        for (auto c : text) cnt[c - 'a']++;
        int x = INT_MAX;
        for (auto c : "ban") {
            if (c == '\0') break;
            x = min(x, cnt[c - 'a']);
        }
        for (auto c : "lo") {
            if (c == '\0') break;
            x = min(x, cnt[c - 'a'] / 2);
        }
        return x;
    }
};