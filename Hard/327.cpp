#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using oset = tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long sum = 0;
        unordered_map<int, int> cnt;
        oset ose;
        ose.insert(make_pair(0, cnt[0]++));
        int ans = 0;

        const function<int(long long)> get = [&](long long r) -> int {
            return ose.order_of_key(make_pair(r + 1, -1));
        };

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans += get(sum - lower) - get(sum - upper - 1);
            ose.insert(make_pair(sum, cnt[sum]++));
        }
        return ans;
    }
};