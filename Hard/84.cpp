class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> le, ri;
        int n = heights.size();
        vector<int> leIdx(n), riIdx(n);
        for (int i = 0; i < n; i++) {
            while (!ri.empty() && ri.back().second > heights[i]) {
                riIdx[ri.back().first] = i;
                ri.pop_back();
            }
            ri.push_back(make_pair(i, heights[i]));
        }
        while (!ri.empty()) {
            riIdx[ri.back().first] = n;
            ri.pop_back();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!le.empty() && le.back().second > heights[i]) {
                leIdx[le.back().first] = i;
                le.pop_back();
            }
            le.push_back(make_pair(i, heights[i]));
        }
        while (!le.empty()) {
            leIdx[le.back().first] = -1;
            le.pop_back();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (riIdx[i] - leIdx[i] - 1));
        }
        return ans;
    }
};