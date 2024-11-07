class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        for (auto ch : s) cnt += ch == c;
        return (cnt) * (cnt + 1) / 2;
    }
};