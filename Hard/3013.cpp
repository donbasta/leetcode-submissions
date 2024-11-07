using ll = long long;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // nums[0] + nums[i] + smallest (k-2) dari nums[i + 1], ..., nums[i + dist]

        int n = nums.size();
        multiset<int> sm, lg;
        ll tot = 0;
        for (int i = n - 1; i >= n - (k - 2); i--) {
            sm.insert(nums[i]);
            tot += nums[i];
        }
        ll ans = 1e18;
        for (int i = n - (k - 1); i >= 1; i--) {
            ans = min(ans, nums[0] + nums[i] + tot);
            if (*sm.rbegin() >= nums[i]) {
                int x = *sm.rbegin();
                sm.erase(sm.find(x));
                tot -= x;
                sm.insert(nums[i]);
                tot += nums[i];
                lg.insert(x);
            } else {
                lg.insert(nums[i]);
            }

            if ((int)sm.size() + (int)lg.size() > dist) {
                if (*sm.rbegin() >= nums[i + dist]) {
                    sm.erase(sm.find(nums[i + dist]));
                    tot -= nums[i + dist];
                    int nw = *lg.begin();
                    lg.erase(lg.begin());
                    sm.insert(nw);
                    tot += nw;
                } else {
                    lg.erase(lg.find(nums[i + dist]));
                }
            }
        }
        return ans;
    }
};