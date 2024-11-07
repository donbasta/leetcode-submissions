class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            ve.emplace_back(height[i], i);
        }
        sort(ve.begin(), ve.end());
        reverse(ve.begin(), ve.end());
        int ans = 0;
        int mxIdx = ve[0].second, mnIdx = ve[0].second, cur = ve[0].first;
        for (int i = 1; i < n; i++) {
            cur = ve[i].first;
            mxIdx = max(mxIdx, ve[i].second);
            mnIdx = min(mnIdx, ve[i].second);
            ans = max(ans, cur * (mxIdx - mnIdx));
        }
        return ans;
    }
};