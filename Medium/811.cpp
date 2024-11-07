class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<vector<string>, int> mp;
        for (auto domain : cpdomains) {
            vector<string> tokens;
            string tmp;
            int cnt;
            for (auto c : domain) {
                if (c == ' ') {
                    cnt = stoi(tmp);
                    tmp.clear();
                } else if (c == '.') {
                    tokens.push_back(tmp);
                    tmp.clear();
                } else {
                    tmp.push_back(c);
                }
            }
            tokens.push_back(tmp);
            int n = tokens.size();
            vector<string> lmao;
            for (int i = n - 1; i >= 0; i--) {
                lmao.push_back(tokens[i]);
                mp[lmao] += cnt;
            }
        }
        vector<string> ret;
        for (auto c : mp) {
            string count = to_string(c.second);
            string domain;
            int n = c.first.size();
            for (int i = n - 1; i >= 0; i--) {
                domain += c.first[i];
                if (i > 0) domain += ".";
            }
            ret.push_back(count + " " + domain);
        }
        return ret;
    }
};