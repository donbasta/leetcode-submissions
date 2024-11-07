class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> la(26, -1), fi(26, n);
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                la[c - 'a'] = max(la[c - 'a'], i);
            } else {
                fi[c - 'A'] = min(fi[c - 'A'], i);
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (la[i] == -1 || fi[i] == n) continue;
            ans += la[i] < fi[i];
        }
        return ans;
    }
};