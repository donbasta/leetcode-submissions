class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ret;
        set<string> se;
        for (auto d : dictionary) {
            se.insert(d);
        }
        vector<string> tokens;
        string buf;
        for (auto c : sentence) {
            if (c == ' ') {
                tokens.push_back(buf);
                buf.clear();
            } else {
                buf += c;
            }
        }
        tokens.push_back(buf);
        for (auto s : tokens) {
            string tmp;
            bool found = false;
            for (auto c : s) {
                tmp += c;
                if (se.count(tmp)) {
                    found = true;
                    ret += tmp;
                    break;
                }
            }
            if (!found) {
                ret += s;
            }
            ret += ' ';
        }
        ret.pop_back();
        return ret;
    }
};