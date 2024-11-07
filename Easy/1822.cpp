class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (auto e : nums) {
            if (e == 0) return 0;
            neg += (e < 0);
        }
        return ((neg & 1) ? -1 : 1);
    }
};