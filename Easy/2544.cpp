class Solution {
public:
    int alternateDigitSum(int n) {
        string st = to_string(n);
        int ans = 0;
        int sg = 1;
        for (auto c : st) {
            ans += sg * (c - '0');
            sg *= -1;
        }
        return ans;
    }
};