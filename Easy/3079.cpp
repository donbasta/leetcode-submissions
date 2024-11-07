class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int x = 0;
        for (auto n : nums) {
            int mx = 0, tmp = n, dig = 0;
            while (tmp) {
                mx = max(mx, tmp % 10);
                tmp /= 10;
                dig++;
            }
            int pw = 1;
            for (int i = 0; i < dig; i++) {
                x += pw * mx;
                pw *= 10;
            }
        }
        return x;
    }
};