class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (auto e : nums) {
            cnt += (e % 2 == 0);
        }
        return cnt >= 2;
    }
};