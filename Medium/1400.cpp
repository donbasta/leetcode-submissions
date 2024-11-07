class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26);
        for (auto c : s) cnt[c - 'a']++;
        int odd = 0;
        for (int i = 0; i < 26; i++) odd += (cnt[i] & 1);
        if (odd > k) return false;
        int sisa = k - odd;
        int rem = 0;
        for (int i = 0; i < 26; i++) rem += (cnt[i] / 2) * 2;
        return (rem >= (((sisa + 1) / 2) * 2));
    }
};