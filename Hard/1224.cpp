class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        int MX = 1e5;
        int ans = 1;
        int cnt[MX + 1];
        memset(cnt, 0, sizeof(cnt));
        cnt[nums[0]]++;
        multiset<int> sizes;
        sizes.insert(1);
        for (int i = 1; i < n; i++) {
            if (cnt[nums[i]] > 0) {
                sizes.erase(sizes.find(cnt[nums[i]]));
            }
            cnt[nums[i]]++;
            sizes.emplace(cnt[nums[i]]);
            if (sizes.size() == 1) {
                ans = max(ans, i + 1);
            } else {
                auto x = sizes.rbegin();
                int greatest = *x;
                ++x;
                auto y = sizes.begin();
                ++y;
                if (*x == *sizes.begin() && (*x + 1) == greatest) {
                    ans = max(ans, i + 1);
                } else if (*sizes.begin() == 1 && greatest == *y) {
                    ans = max(ans, i + 1);
                }
            }
        }
        return ans;
    }
};