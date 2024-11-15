class Solution {
public:
    string getHappyString(int n, int k) {
        int tot = 3;
        for (int i = 1; i < n; i++) tot *= 2;
        if (tot < k) return "";

        string ret;
        if (k <= tot / 3) ret.push_back('a');
        else if (k <= (2 * tot) / 3) ret.push_back('b'), k -= tot / 3;
        else ret.push_back('c'), k -= (2 * tot) / 3;
        tot /= 3;

        for (int i = 1; i < n; i++) {
            int prv = ret.back() - 'a';
            vector<int> ch;
            for (int j = 0; j < 3; j++) {
                if (j == prv) continue;
                ch.push_back(j);
            }
            if (k <= tot / 2) {
                ret.push_back(ch[0] + 'a');
            } else {
                ret.push_back(ch[1] + 'a'), k -= tot / 2;
            }
            tot /= 2;
        }
        return ret;
    }
};