class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        map<int, int> cnt;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == key) {
                cnt[nums[i + 1]]++;
            }
        }
        int ans = -1;
        int mx = 0;
        for (auto e : cnt) {
            if (e.second > mx) {
                mx = e.second;
                ans = e.first;
            }
        }
        return ans;
    }
};