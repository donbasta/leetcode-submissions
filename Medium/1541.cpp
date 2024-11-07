class Solution {
public:
    int minInsertions(string s) {
        string tmp;
        int len = 0;
        int ans = 0;
        for (auto c : s) {
            if (c == '(') {
                if (!tmp.empty() && tmp.back() == ')') {
                    if (len & 1) ans++, tmp.push_back(')');
                }
            }
            if (!tmp.empty() && tmp.back() != c) len = 0;
            len++;
            tmp.push_back(c);
        }
        if (!tmp.empty() && tmp.back() == ')' && (len & 1)) {
            ans++, tmp.push_back(')');
        }
        int sz = tmp.size();
        int itr = 0;
        int pref = 0;
        while (itr < sz) {
            if (tmp[itr] == '(') {
                pref++;
                itr++;
            } else {
                pref--;
                if (pref < 0) {
                    pref = 0;
                    ans++;
                }
                itr += 2;
            }
        }
        ans += pref * 2;
        return ans;
    }
};