class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ans = -1;
        int cur = count(s.begin(), s.end(), '1');
        for (int i = 0; i < n - 1; i++) {
            cur += (s[i] == '0') - (s[i] == '1');
            ans = max(ans, cur);
        }
        return ans;
    }
};