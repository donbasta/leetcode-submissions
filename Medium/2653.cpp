class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> tmp;
        for (int i = 0; i < k; i++) {
            tmp.push_back(nums[i]);
        }
        sort(tmp.begin(), tmp.end());
        multiset<int> s1, s2;
        for (int i = 0; i < x; i++) {
            s1.insert(tmp[i]);
        }
        for (int i = x; i < k; i++) {
            s2.insert(tmp[i]);
        }

        auto erase = [&](int x) {
            assert (!s2.empty());
            if (*s2.begin() <= x) {
                s2.erase(s2.find(x));
            } else {
                s1.erase(s1.find(x));
                s1.insert(*s2.begin());
                s2.erase(s2.find(*s2.begin()));
            }
        };
        auto insert = [&](int x) {
            assert (!s1.empty());
            int mx = *s1.rbegin();
            if (x < mx) {
                s2.insert(mx);
                s1.erase(s1.find(mx));
                s1.insert(x);
            } else {
                s2.insert(x);
            }
        };

        vector<int> ret;
        ret.push_back(min(0, *s1.rbegin()));
        for (int i = k; i < n; i++) {
            insert(nums[i]);
            erase(nums[i - k]);
            ret.push_back(min(0, *s1.rbegin()));
        }
        return ret;
    }
};