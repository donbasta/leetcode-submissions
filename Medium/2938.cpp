class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long ans = 0;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                ans += (i - ptr);
                ptr++;
            }
        }
        return ans;
    }
};