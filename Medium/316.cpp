class Solution {
public:
    string removeDuplicateLetters(string s) {
        int sisa[26], ada[26];
        memset(sisa, 0, sizeof(sisa));
        memset(ada, 0, sizeof(ada));
        for (auto c : s) sisa[c - 'a']++;
        string ret;
        for (auto c : s) {
            while ((!ret.empty()) && (!ada[c - 'a']) && (ret.back() >= c) && (sisa[ret.back() - 'a'] > 0)) {
                ada[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            sisa[c - 'a']--;
            if (!ada[c - 'a']) {
                ada[c - 'a'] = true;
                ret.push_back(c);
            }
        }
        return ret;
    }
};