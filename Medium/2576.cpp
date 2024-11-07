class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        multiset<int> se;
        for (int i = 0; i < n / 2; i++) {
            se.insert(nums[i]);
        } 
        int ans = 0;
        for (int i = n - 1; i >= n / 2; i--) {
            if (se.empty()) break;
            auto ptr = se.upper_bound(nums[i] / 2);
            if (ptr == se.begin()) break;
            --ptr;
            se.erase(ptr);
            ans += 2;
        }
        return ans;
    }
};