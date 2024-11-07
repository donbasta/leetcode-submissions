class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        //index i become the top:
        // can: i, i+2, i+4, ... i+2x 
        // cant: i+1,
        // can: i+3, i+5, ... if i >= 1
        // if i == 0: i+3, i+5, ... bisa if sz >= 2
        
        int ans = -1;
        int sz = nums.size();
        auto ok = [&](int idx, int moves) -> bool {
            if (idx > 0) {
                if (moves >= idx && moves != (idx + 1)) return true;
                else return false;
            }
            if (sz == 1) {
                return (moves % 2 == 0);
            }
            return (moves != 1);
        };

        for (int i = 0; i < sz; i++) {
            if (ok(i, k)) {
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};