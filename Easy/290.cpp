class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const function<vector<string>(string)> splitSpace = [&](string str) -> vector<string> {
            string current;
            vector<string> ret;
            for (auto c : str) {
                if (c == ' ') {
                    ret.push_back(current);
                    current.clear();
                } else {
                    current.push_back(c);
                }
            }
            ret.push_back(current);
            return ret;
        };
        vector<string> lol = splitSpace(s);
        if (lol.size() != pattern.length()) return false;
        unordered_map<char, string> mp;
        unordered_map<string, char> rmp;
        for (int i = 0; i < lol.size(); i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (rmp.find(lol[i]) != rmp.end()) return false;
                mp[pattern[i]] = lol[i];
                rmp[lol[i]] = pattern[i];
            } else {
                if (mp[pattern[i]] != lol[i]) return false;
            }
        }
        return true;
    }
};