class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long cntDummy = accumulate(cost.begin(), cost.end(), 0ll);
        long long half = (cntDummy + 1) / 2;
        long long tmp = 0;
        vector<pair<long long, long long>> hihi;
        for (int i = 0; i < nums.size(); i++) {
            hihi.emplace_back(nums[i], cost[i]);
        }
        sort(hihi.begin(), hihi.end());
        int pivot = -1;
        for (int i = 0; i < hihi.size(); i++) {
            tmp += hihi[i].second;
            if (tmp >= half) {
                pivot = i;
                break;
            };
        }
        long long ans = 0;
        long long x = hihi[pivot].first;
        for (int i = 0; i < nums.size(); i++) {
            ans += 1ll * abs(x - nums[i]) * cost[i];
        }
        return ans;
    }
};