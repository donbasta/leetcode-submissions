class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int cc = -1;
        for (int i = 0; i <= n - 3; i++) {
            int a = num[i], b = num[i + 1], c = num[i + 2];
            if (a == b && a == c) {
                cc = max(cc, a - '0');
            }
        }
        if (cc == -1) return "";
        string ret;
        for (int i = 0; i < 3; i++) ret.push_back((char)(cc + '0'));
        return ret;
    }
};