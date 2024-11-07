class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> ok(26);
        for (auto c : allowed) ok[c - 'a'] = true;
        int ans = 0;
        for (auto w : words) {
            bool noo = false;
            for (auto c : w) {
                if (!ok[c - 'a']) {
                    noo = true;
                    break;
                }
            }
            if (!noo) ans++;
        }
        return ans;
    }
};