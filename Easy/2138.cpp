class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ret;
        for (int i = 0; i < n; i += k) {
            if (i + k > n) {
                string tmp = s.substr(i, n - i);
                while (tmp.length() < k) tmp.push_back(fill);
                ret.push_back(tmp);
            } else {
                ret.push_back(s.substr(i, k));
            }
        }
        return ret;
    }
};