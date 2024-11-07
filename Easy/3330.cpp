class Solution {
public:
    int possibleStringCount(string word) {
        int last = 0;
        int n = word.size();
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] != word[i - 1]) {
                ans += i - last - 1;
                last = i;
            }
        }
        ans += n - last - 1;
        return ans;
    }
};