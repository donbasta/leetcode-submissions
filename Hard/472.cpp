class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string& a, string& b) -> bool {
            return a.length() < b.length();
        }); 
        vector<string> ret;
        set<string> se;

        auto ok = [&](string& S) -> bool {
            int len = S.length();
            bool dp[len + 1];
            memset(dp, 0, sizeof(dp));
            dp[len] = true;
            for (int i = len - 1; i >= 0; i--) {
                string tmp;
                for (int j = i; j < len; j++) {
                    tmp.push_back(S[j]);
                    if (se.count(tmp) && dp[j + 1]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[0];
        };

        for (auto w : words) {
            if (ok(w)) {
                ret.push_back(w);
            }
            se.insert(w);
        }
        return ret;
    }
};