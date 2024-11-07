class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t = s;
        int sisa = k;
        for (int i = 0; i < n; i++) {
            //move ke bawah
            int bawah = s[i] - 'a';
            //move ke atas
            int atas = 26 - (s[i] - 'a');
            if (min(bawah, atas) <= sisa) {
                sisa -= min(bawah, atas);
                t[i] = 'a';
            } else {
                t[i] = s[i] - sisa;
                break;
            }
        }
        return t;
    }
};