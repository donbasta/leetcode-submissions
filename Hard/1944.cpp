class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<pair<int, int>> ve;
        int n = heights.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!ve.empty() && ve.back().first < heights[i]) {
                ans[ve.back().second]++;
                ve.pop_back();
            }
            if (!ve.empty()) {
                ans[ve.back().second]++;
            }
            ve.emplace_back(heights[i], i);
        }
        // for (int i = 0; i < ve.size(); i++) {
        //     ans[ve[i].second] += (ve.size() - i - 1);
        // }
        return ans;
    } 
};