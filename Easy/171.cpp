class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        long long pw = 1;
        int ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            ret += (columnTitle[i] - 'A' + 1) * pw;
            pw *= 26;
        }
        return ret;
    }
};