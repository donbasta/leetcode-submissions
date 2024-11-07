class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        for (int i = 0; i < str1.length(); i++) {
            int cek = str2[idx] - 'a';
            int now = str1[i] - 'a';
            int lol = (now + 1 - cek) % 26;
            if (lol < 0) lol += 26;
            if ((now == cek) || (lol == 0)) idx++;
            if (idx == str2.length()) return true;
        }
        return false;
    }
};