class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string ret;
        char now = s[0];
        int len = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == now) len++;
            else {
                ret.push_back((char) (len + '0'));
                ret.push_back(now);
                now = s[i];
                len = 1;
            }
        }
        ret.push_back((char) (len + '0'));
        ret.push_back(now);
        return ret;
    }
};