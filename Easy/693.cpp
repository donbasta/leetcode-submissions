class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> s;
        while (n) {
            s.push_back(n & 1);
            n >>= 1;
        }
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] == s[i + 1]) return false;
        }
        return true;
    }
};