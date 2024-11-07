class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        vector<pair<int, int>> data;
        for (int i = 0; i < n; i++) {
            while (!data.empty() && data.back().first < temperatures[i]) {
                ans[data.back().second] = i - data.back().second;
                data.pop_back();
            }
            data.emplace_back(temperatures[i], i);
        }
        return ans;
    }
};