class Solution {
public:
    int minDeletions(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        sort(cnt, cnt + 26, greater<>());
        int last = cnt[0];
        int del = 0;
        for (int i = 1; i < 26; i++) {
            if (cnt[i] == 0) break;
            if (last == 1) {
                del += cnt[i];
                continue;
            }
            if (cnt[i] >= last) {
                del += (cnt[i] - last + 1);
                last--;
            } else {
                last = cnt[i];
            }
        }
        return del;
    }
};