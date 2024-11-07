class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        vector<int> tmp, unq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            tmp.push_back(nums[i] - i);
            unq.push_back(nums[i] - i);
        }
        sort(unq.begin(), unq.end());
        unq.resize(unique(unq.begin(), unq.end()) - unq.begin());
        unordered_map<int, int> ump;
        int sz = unq.size();
        for (int i = 0; i < sz; i++) {
            ump[unq[i]] = i;
        }

        const long long INF = 1e18;
        vector<long long> bit(sz + 1, -INF);
        const function<void(int, long long)> upd = [&](int idx, long long val) {
            idx++;
            while (idx <= sz) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };
        const function<long long(int)> get = [&](int idx) -> long long {
            idx++;
            long long ret = -INF;
            while (idx > 0) {
                ret = max(ret, bit[idx]);
                idx -= idx & -idx;
            }
            return ret;
        };

        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            int pos = ump[tmp[i]];
            long long x = get(pos);
            long long cur;
            dp[i] = max(1ll * nums[i], x + nums[i]);
            upd(pos, dp[i]);
        }

        long long ans = -INF;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};