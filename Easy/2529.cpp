class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for (auto e : nums) {
            if (e > 0) pos++;
            else if (e < 0) neg++;
        }
        return max(pos, neg);
    }
};