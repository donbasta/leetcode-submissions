class WordFilter {
private:
    unordered_map<string, int> mp;
    vector<string> dict;
public:
    WordFilter(vector<string>& words) {
        dict = words;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int len = words[i].length();
            vector<string> pref(len), suf(len);
            for (int j = 0; j < len; j++) pref[j] = words[i].substr(0, j + 1);
            for (int j = 0; j < len; j++) suf[j] = words[i].substr(j, len - j);
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < len; k++) {
                    string tmp = pref[j] + "#" + suf[k];
                    mp[tmp] = max(i, mp[tmp]);
                }
            }
        }
    }

    int f(string pref, string suff) {
        string tmp = pref + "#" + suff;
        if (!mp.count(tmp)) return -1;
        return mp[tmp];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */