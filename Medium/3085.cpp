class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26);
        for (auto c : word) cnt[c - 'a']++;
        sort(cnt.begin(), cnt.end());
        int prf = 0, ans = 2e9;
        vector<int> suf(27);
        for (int i = 25; i >= 0; i--) suf[i] = suf[i + 1] + cnt[i];
        for (int i = 0; i < 26; i++) {
            int lo = cnt[i];
            int nx = upper_bound(cnt.begin(), cnt.end(), lo + k) - cnt.begin();
            ans = min(ans, prf + suf[nx] - (lo + k) * (26 - nx));
            prf += cnt[i];
        }
        return ans;
    }
};