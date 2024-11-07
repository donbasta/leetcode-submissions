class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string buf;
        string ret;
        map<string, string> mp;
        for (auto k : knowledge) {
            mp[k[0]] = k[1];
        }
        bool parsing_key = false;
        for (auto c : s) {
            if (c == '(') {
                parsing_key = true;
            } else if (c == ')') {
                if (mp.find(buf) == mp.end()) {
                    ret.push_back('?');
                } else {
                    ret += mp[buf];
                }
                buf.clear();
                parsing_key = false;
            } else {
                if (parsing_key) {
                    buf.push_back(c);
                } else {
                    ret.push_back(c);
                }
            }
        }
        return ret;
    }
};