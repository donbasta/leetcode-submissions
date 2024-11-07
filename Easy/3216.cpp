class Solution {
public:
    string getSmallestString(string s) {
        string ans = s;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (abs(s[i] - s[i + 1]) % 2 == 0) {
                string tmp = s;
                swap(tmp[i], tmp[i + 1]);
                ans = min(ans, tmp);
            }
        }
        return ans;
    }
};