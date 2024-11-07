class MagicDictionary {
public:
    vector<unordered_map<long long, bool>> ump;
    long long mod = 1e9 + 7;
    long long base = 31;

    MagicDictionary() {
        ump.resize(101);
    }

    long long getHash(string s) {
        long long ret = 0;
        long long pw = 1;
        for (int i = 0; i < s.length(); i++) {
            ret = (ret + pw * (s[i] - 'a' + 1)) % mod;
            pw = pw * base % mod;
        }
        return ret;
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto s : dictionary) {
            int len = s.length();
            long long pw = 1;
            long long lmao = getHash(s);
            for (int i = 0; i < len; i++) {
                int cur = s[i] - 'a';
                lmao = (lmao - 1ll * (cur + 1) * pw) % mod;
                if (lmao < 0) lmao += mod;
                for (int j = 0; j < 26; j++) {
                    lmao = (lmao + pw) % mod;
                    if (j == cur) continue;
                    ump[len][lmao] = true;
                }
                lmao = (lmao - 1ll * (26) * pw) % mod;
                lmao = (lmao + 1ll * (cur + 1) * pw) % mod;
                if (lmao < 0) lmao += mod;
                pw = (pw * base) % mod;
            }
        }
    }
    
    bool search(string searchWord) {
        int len = searchWord.length();
        long long lmao = getHash(searchWord);
        return (ump[len].find(lmao) != ump[len].end());
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */