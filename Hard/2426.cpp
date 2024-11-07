#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        oset ose;
        ose.insert(make_pair(nums2[0] - nums1[0], 0));
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int need = nums2[i] - nums1[i] - diff;
            int idx = ose.order_of_key(make_pair(need, -1));
            ans += (i - idx);
            ose.insert(make_pair(nums2[i] - nums1[i], i));
        }
        return ans;
    }
};