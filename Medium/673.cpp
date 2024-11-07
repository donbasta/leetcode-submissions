struct BIT {
    int MOD = INT_MAX;
    vector<long long> tree;
    int n;
    BIT() {}
    BIT(int n) : n(n) {tree.resize(n + 1);}
    long long get(int idx) {
        long long ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            ret %= MOD;
            idx -= idx & (-idx);
        }
        return ret;
    }
    void add(int idx, long long val) {
        while (idx <= n) {
            tree[idx] += val;
            tree[idx] %= MOD;
            idx += idx & (-idx);
        }
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int MOD = INT_MAX;
        int n = nums.size();
        vector<int> cpy = nums;
        sort(cpy.begin(), cpy.end());
        cpy.resize(unique(cpy.begin(), cpy.end()) - cpy.begin());
        unordered_map<int, int> ump;
        for (int i = 0; i < cpy.size(); i++) {
            ump[cpy[i]] = i + 1;
        }

        vector<vector<long long>> dp(n, vector<long long>(n + 1));
        vector<BIT> bit(n + 1);
        for (int i = 1; i <= n; i++) {
            bit[i] = BIT(cpy.size() + 1);
        }
        dp[0][1] = 1;
        bit[1].add(ump[nums[0]], 1);
        for (int i = 1; i < n; i++) {
            dp[i][1] = 1;
            bit[1].add(ump[nums[i]], 1);
            for (int j = 2; j <= i + 1; j++) {
                dp[i][j] = bit[j - 1].get(ump[nums[i]] - 1);
                bit[j].add(ump[nums[i]], dp[i][j]);
            }
        }
        int lis = 1;
        for (int len = n; len >= 1; len--) {
            for (int i = n - 1; i >= 0; i--) {
                if (dp[i][len] > 0) {
                    lis = len;
                    break;
                }
            }
            if (lis > 1) break;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i][lis];
            ans %= MOD;
        }
        return ans;
    }
};