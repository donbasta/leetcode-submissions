#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        // nums[k] <= 0
        // ...
        // nums[n - 1] <= n - 1 - k
        // nums[0] <= n - k
        // ...
        // nums[k - 1] <= n - 1

        // p[i] = nums[i] - i;
        // p[k], ..., p[n - 1] <= -k
        // p[0], ..., p[k - 1] <= n - k

        int n = nums.size();
        vector<int> ve(n), L(n), R(n);
        for (int i = 0; i < n; i++) {
            ve[i] = nums[i] - i;
        }
        pbds ds;
        unordered_map<int, int> cnt;
        for (int i = 1; i < n; i++) {
            ds.insert(make_pair(ve[i - 1], cnt[ve[i - 1]]++));
            L[i] = ds.order_of_key(make_pair(n - i + 1, -1));
        }
        ds.clear(), cnt.clear();
        for (int i = n - 1; i >= 1; i--) {
            ds.insert(make_pair(ve[i], cnt[ve[i]]++));
            R[i] = ds.order_of_key(make_pair(1 - i, -1));
        }
        int ans = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) ans += nums[i] <= i;
        for (int i = 1; i < n; i++) {
            if (L[i] + R[i] > ans) {
                ans = L[i] + R[i];
                idx = i;
            }
        }
        return idx;
    }
};