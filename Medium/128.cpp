class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> num_set;
        for (auto num: nums) num_set[num] = true;
        int ans = 0;
    
        
        for (auto num : nums) {
            if (num_set.find(num - 1) != num_set.end()) continue;
            int cur = num, curLen = 1;
            while (num_set.find(cur + 1) != num_set.end()) {
                cur++, curLen++;
            }
            ans = max(ans, curLen);
        }
        
        return ans;
    }
};