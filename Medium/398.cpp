class Solution {
private:
    unordered_map<int, vector<int>> mp;

public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            this->mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
        const long long MX = 4294967296;
        int mxSize = mp[target].size();
        int randIdx = int((double(rng32()) / MX) * mxSize);
        return mp[target][randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */