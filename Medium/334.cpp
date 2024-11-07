class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        multiset<int> kiri, kanan;
        kanan.emplace(nums[n - 1]);
        for (int i = 0; i < n - 2; i++) kiri.emplace(nums[i]);
        for (int i = n - 2; i >= 1; i--) {
            int minLeft = *kiri.begin();
            int maxRight = *kanan.rbegin();
            if ((minLeft < nums[i]) && (maxRight > nums[i])) {
                return true;
            }
            kanan.emplace(nums[i]);
            kiri.erase(kiri.find(nums[i - 1]));
        }
        return false;
    }
};