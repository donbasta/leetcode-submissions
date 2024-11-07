class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int tot = 0;
        for (auto n : nums) {
            if (n % 6 == 0) {
                tot += n;
                cnt++;
            }
        }
        if (cnt == 0) return 0;
        return tot / cnt;
    }
};