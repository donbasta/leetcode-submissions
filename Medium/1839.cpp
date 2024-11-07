class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int len = 1;
        char cur = word[0];
        int cnt = 1;
        int ans = 0;
        int n = word.size();
        for (int i = 1; i < n; i++) {
            if (word[i] >= word[i - 1]) {
                cnt += word[i] > word[i - 1];
                len++;
            } else {
                if (cnt == 5) ans = max(ans, len);
                len = cnt = 1;
                cur = word[i];
            }
        }
        if (cnt == 5) ans = max(ans, len);
        return ans;
    }
};