class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int ans = 0;
        while (true) {
            int i = 1;
            int sw = 0;
            while (i < n) {
                if (s[i] == '1' && s[i - 1] == '0') {
                    swap(s[i], s[i - 1]);
                    i += 2;
                    sw++;
                } else {
                    i++;
                }
            }
            if (sw == 0) {
                break;
            }
            ans++;
        }
        return ans;
    }
};