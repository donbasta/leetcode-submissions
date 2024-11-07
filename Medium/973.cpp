class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long, vector<int>>> hehe;
        for (auto e : points) {
            hehe.emplace_back(e[0] * e[0] + e[1] * e[1], e);
        }
        sort(hehe.begin(), hehe.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(hehe[i].second);
        }
        return ans;
    }
};