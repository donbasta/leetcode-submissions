#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using oset = tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        oset ose;
        int n = nums.size();
        ose.insert(make_pair(nums[0], cnt[nums[0]]++));
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += (i - (ose.order_of_key(make_pair(2LL * nums[i] + 1, -1LL))));
            ose.insert(make_pair(nums[i], cnt[nums[i]]++));
        }
        return ans;
    }
};