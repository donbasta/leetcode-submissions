class Solution {
public:
    string reformat(string s) {
        vector<char> alpha, numer;
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                alpha.push_back(c);
            } else {
                numer.push_back(c);
            }
        }
        if (abs((int)alpha.size() - (int)numer.size()) > 1) {
            return "";
        }
        vector<char> p = alpha, q = numer;
        if ((int)p.size() < (int)q.size()) p.swap(q);
        string ret((int)s.size(), '\0');
        for (int i = 0; i < (int)s.size(); i += 2) {
            ret[i] = p[i / 2];
        }
        for (int i = 1; i < (int)s.size(); i += 2) {
            ret[i] = q[i / 2];
        }
        return ret;
    }
};