class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> mn_suf(n);
        mn_suf[n - 1] = s.back();
        for (int i = n - 2; i >= 0; i--) {
            mn_suf[i] = min(mn_suf[i + 1], s[i]);
        }
        vector<int> tmp(26, n), R(n, n);
        for (int i = n - 1; i >= 0; i--) {
            R[i] = tmp[s[i] - 'a'];
            tmp[s[i] - 'a'] = i;
        }
        char mn = mn_suf[0];
        string ret;
        string st;
        for (int i = 0; i < n; i++) {
            if (s[i] == mn) {
                ret.push_back(s[i]);
                if (R[i] == n && i < n - 1) {
                    mn = mn_suf[i + 1];
                    while (!st.empty() && st.back() <= mn) {
                        ret.push_back(st.back());
                        st.pop_back();
                    }
                }
            } else {
                st.push_back(s[i]);
            }
        }
        reverse(st.begin(), st.end());
        ret += st;
        return ret;
    }
};