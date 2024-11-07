class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> div;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                div.push_back(i);
                if (i * i != k) div.push_back(k / i);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int lmao = k / __gcd(k, nums[i]);
            ans += mp[lmao];
            for (auto e : div) {
                if (nums[i] % e == 0) mp[e]++;
            }
        }
        return ans;
    }
};
