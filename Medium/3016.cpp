class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (auto e : word) {
            cnt[e - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<>());
        int ans = 0;
        int cur = 1, sisa = 8;
        for (int i = 0; i < 26; i++) {
            if (sisa == 0) {
                cur++, sisa = 8;
            }
            ans += cnt[i] * cur;
            sisa--;
        }
        return ans;
    }
};