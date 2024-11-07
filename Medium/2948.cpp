class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            ve.emplace_back(nums[i], i);
        }
        sort(ve.begin(), ve.end());
        vector<int> t1, t2, ans(n);
        t1.push_back(ve[0].first);
        t2.push_back(ve[0].second);
        for (int i = 1; i < n; i++) {
            if (ve[i].first > limit + ve[i - 1].first) {
                sort(t2.begin(), t2.end());
                for (int j = 0; j < (int)t2.size(); j++) {
                    ans[t2[j]] = t1[j];
                }
                t1.clear();
                t2.clear();
            }
            t1.push_back(ve[i].first);
            t2.push_back(ve[i].second);
        }
        sort(t2.begin(), t2.end());
        for (int j = 0; j < (int)t2.size(); j++) {
            ans[t2[j]] = t1[j];
        }
        return ans;
    }
};