#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> ri;
        ordered_set oset;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            oset.erase(make_pair(-ri[nums[i]], nums[i]));
            ri[nums[i]] = i;
            oset.insert(make_pair(-ri[nums[i]], nums[i]));
            if (oset.size() < k) continue;
            pair<int, int> A = *oset.find_by_order(k - 1);
            if (oset.size() == k) {
                int R = -A.first;
                ret += (R + 1);
            } else {
                pair<int, int> B = *oset.find_by_order(k);
                int L = -B.first, R = -A.first;
                ret += (R - L);
            }
        }
        return ret;
    }
};