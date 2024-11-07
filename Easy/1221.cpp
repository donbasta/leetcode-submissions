class Solution {
public:
    int balancedStringSplit(string s) {
        int cur = 0;
        int ans = 0;
        for (auto c : s) {
            if (c == 'R') cur++;
            else cur--;
            if (cur == 0) ans++;
        }
        return ans;
    }
};