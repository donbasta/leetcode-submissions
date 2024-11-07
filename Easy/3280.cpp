class Solution {
public:
    string convertDateToBinary(string date) {
        string buf;
        string ret;

        auto conv = [&](string x) -> string {
            int z = stoi(x);
            string ret;
            while (z) {
                if (z & 1) ret.push_back('1');
                else ret.push_back('0');
                z >>= 1;
            }
            reverse(ret.begin(), ret.end());
            return ret;
        };

        for (auto c : date) {
            if (c == '-') {
                ret += conv(buf);
                ret.push_back('-');
                buf.clear();
            } else {
                buf.push_back(c);
            }
        }
        ret += conv(buf);
        return ret;
    }
};