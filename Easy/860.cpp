class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0, c = 0;
        for (auto d : bills) {
            if (d == 5) a++;
            else if (d == 10) {
                if (a == 0) return false;
                a--, b++;
            } else {
                if (a > 0 && b > 0) {
                    a--, b--;
                } else if (a >= 3) {
                    a -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};