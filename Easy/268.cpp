class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int c = nums.size(), sor = 0;
        for (int i = 0; i <= c; i++) sor ^= i;
        for (auto e : nums) sor ^= e;
        return sor;
    }
};