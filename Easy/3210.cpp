class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ret = s;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            ret[i] = s[(i + k) % n];
        }
        return ret;
    }
};