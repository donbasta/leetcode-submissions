class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> vis(n + 1);
        vector<vector<string>> memo(n + 1);
        unordered_map<string, bool> dict;
        for (auto w : wordDict) dict[w] = true;

        const function<vector<string>(int)> dp = [&](int idx) -> vector<string> {
            if (vis[idx]) return memo[idx];
            vector<string> ret;
            if (dict.find(s.substr(0, idx + 1)) != dict.end()) {
                ret.push_back(s.substr(0, idx + 1));
            }

            for (int i = 1; i <= idx; i++) {
                string last_word = s.substr(i, idx - i + 1);
                if (dict.find(last_word) == dict.end()) continue;
                vector<string> hehe = dp(i - 1);
                if (hehe.empty()) continue;
                for (auto e : hehe) {
                    ret.push_back(e + " " + last_word);
                }
            }

            memo[idx] = ret;
            vis[idx] = true;
            return ret;
        };

        return dp(n - 1);
    }
};