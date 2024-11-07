class Solution {
public:
    int countAsterisks(string s) {
        bool open = true;
        int ans = 0;
        for (auto c : s) {
            if (c == '|') open = !open;
            else if (c == '*') {
                ans += open;
            }
        }
        return ans;
    }
};