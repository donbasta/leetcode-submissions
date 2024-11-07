class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> le(n), ri(n);
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && tmp.back().second > nums[i]) {
                ri[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, nums[i]);
        }
        while (!tmp.empty()) {
            ri[tmp.back().first] = n;
            tmp.pop_back();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && tmp.back().second > nums[i]) {
                le[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, nums[i]);
        }
        while (!tmp.empty()) {
            le[tmp.back().first] = -1;
            tmp.pop_back();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int kiri = le[i] + 1;
            int kanan = ri[i] - 1;
            int len = 0;
            if (k >= kiri && k <= kanan) {
                ans = max(ans, nums[i] * (ri[i] - le[i] - 1));
            }
        }
        return ans;
    }
};