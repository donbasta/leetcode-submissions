class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto c : s) {
            for (auto v : "aeiou") {
                if (c == v) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt > 0;
    }
};