class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        auto conv = [&](const string& st) -> string {
            string ret = st;
            for (auto& c : ret) {
                int ord = (c - 'a' + 1) % 26;
                c = (char)(ord + 'a');
            }
            return ret;
        };
        while ((int)s.length() < k) {
            string ns = conv(s);
            s += ns;
        }
        return s[k - 1];
    }
};