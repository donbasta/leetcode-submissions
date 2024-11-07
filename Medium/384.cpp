class Solution {
public:
    vector<int> original;

    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> shuffled = original;
        for (int i = shuffled.size() - 1; i >= 1; i--) {
            int a = rand() % (i + 1);
            swap(shuffled[a], shuffled[i]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */