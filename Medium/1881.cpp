class Solution {
public:
    string maxValue(string n, int x) {
        string ret;
        char ch = x + '0';
        int len = n.length();
        bool ins = false;
        if (n[0] == '-') {
            ret += '-';
            for (int i = 1; i < len; i++) {
                if (!ins && n[i] > ch) {
                    ins = true;
                    ret += ch;
                }
                ret += n[i];
            }
        } else {
            for (int i = 0; i < len; i++) {
                if (!ins && n[i] < ch) {
                    ins = true;
                    ret += ch;
                } 
                ret += n[i];
            }
        }
        if (!ins) ret += ch;
        return ret;
    }
};