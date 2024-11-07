class Solution {
public:
    int minimumChairs(string s) {
        int tmp = 0;
        int ans = 0;
        for (auto c : s) {
            if (c == 'E') tmp++;
            else tmp--;
            ans = max(ans, tmp);
        }
        return ans;
    }
};