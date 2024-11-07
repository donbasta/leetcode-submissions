class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        for (auto c : word1) cnt1[c - 'a']++;
        for (auto c : word2) cnt2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            int tot = cnt1[i] + cnt2[i];
            if (tot > 0 && (cnt1[i] == tot || cnt2[i] == tot)) return false;
        }
        sort(cnt1.begin(), cnt1.end()), sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};