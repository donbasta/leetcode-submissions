class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int cur = 0;
        const int M = 100;
        for (auto c : s) {
            if (cur + widths[c - 'a'] > M) {
                line++;
                cur = widths[c - 'a'];
            } else {
                cur += widths[c - 'a'];
            }
        }
        return vector<int>{line, cur};
    }
};