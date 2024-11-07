class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xoxo = 0;
        for (auto num : nums) xoxo ^= num;
        if (xoxo == 0) return true;
        return (!(nums.size() & 1));
    }
};