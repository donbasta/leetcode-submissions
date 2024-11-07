#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        Tree<pair<int, int>> t1, t2;
        vector<int> a1, a2;
        a1.push_back(nums[0]), a2.push_back(nums[1]);
        t1.insert(make_pair(nums[0], 0));
        t2.insert(make_pair(nums[1], 1));
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            int gc1 = (int)a1.size() - t1.order_of_key(make_pair(nums[i] + 1, -1));
            int gc2 = (int)a2.size() - t2.order_of_key(make_pair(nums[i] + 1, -1));
            if (gc1 > gc2 || (gc1 == gc2 && a1.size() <= a2.size())) {
                a1.push_back(nums[i]);
                t1.insert(make_pair(nums[i], i));
            } else {
                a2.push_back(nums[i]);
                t2.insert(make_pair(nums[i], i));
            }
        }
        for (auto e : a2) a1.push_back(e);
        return a1;
    }
};