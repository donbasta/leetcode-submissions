class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp;
        for (char c : "qwertyuiopQWERTYUIOP") mp[c] = 1;
        for (char c : "asdfghjklASDFGHJKL") mp[c] = 2;
        for (char c : "zxcvbnmZXCVBNM") mp[c] = 3;
        vector<string> ret;
        for (auto w : words) {
            int lvl = mp[w[0]];
            bool ok = true;
            for (int i = 1; i < (int)w.length(); i++) {
                if (mp[w[i]] != lvl) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret.push_back(w);
            }
        }
        return ret;
    }
};