class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        if (k == 1) {
            for (auto e : nums) ret.push_back(double(e));
            return ret;
        }
        int n = nums.size();
        multiset<int> l, r, tmp;
        for (int i = 0; i < k; i++) tmp.insert(nums[i]);
        int ptr = 0;
        for (auto c : tmp) {
            if (ptr < ((k + 1) / 2)) l.insert(c);
            else r.insert(c);
            ptr++;
        }

        auto median = [&]() -> double {
            if (l.size() > r.size()) return double(*l.rbegin());
            return (double(*l.rbegin()) + double(*r.begin())) / 2;
        };

        ret.push_back(median());
        for (int i = k; i < n; i++) {
            int cur = nums[i], del = nums[i - k];
            if (del <= *l.rbegin()) {
                l.erase(l.find(del));
                if (l.size() < r.size()) {
                    int tt = *r.begin();
                    r.erase(r.find(tt));
                    l.insert(tt);
                }
            } else {
                r.erase(r.find(del));
                if (l.size() - r.size() > 1) {
                    int tt = *l.rbegin();
                    l.erase(l.find(tt));
                    r.insert(tt);
                }
            }
            if (cur <= *l.rbegin()) {
                l.insert(cur);
                if (l.size() - r.size() > 1) {
                    int tt = *l.rbegin();
                    l.erase(l.find(tt));
                    r.insert(tt);
                }
            } else {
                r.insert(cur);
                if (l.size() < r.size()) {
                    int tt = *r.begin();
                    r.erase(r.find(tt));
                    l.insert(tt);
                }
            }
            ret.push_back(median());
        }
        return ret;
    }
};