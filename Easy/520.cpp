class Solution {
public:
    bool detectCapitalUse(string word) {
        auto is_capital = [&](char c) -> bool { return c >= 'A' && c <= 'Z'; };
        int n = word.size();
        int cnt_capital = 0;
        int idx_capital = -1;
        for (int i = 0; i < n; i++) {
            if (is_capital(word[i])) {
                cnt_capital++, idx_capital = i;
            }
        }
        return (cnt_capital == n) || (cnt_capital == 0) || ((cnt_capital == 1) && (idx_capital == 0));
    }
};