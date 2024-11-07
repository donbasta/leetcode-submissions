class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto n : nums) {
            if (n <= 9) a += n;
            else b += n;
        }
        if (a != b) return true;
        return false;
    }
};