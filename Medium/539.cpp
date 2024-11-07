class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (auto e : timePoints) {
            string hr = e.substr(0, 2);
            string mn = e.substr(3, 2);
            int H = stoi(hr), M = stoi(mn);
            int lmao = H * 60 + M;
            mins.push_back(lmao);
            mins.push_back(lmao + 1440);
        }
        sort(mins.begin(), mins.end());
        int ret = 2e9;
        for (int i = 1; i < mins.size(); i++) {
            ret = min(ret, mins[i] - mins[i - 1]);
        }
        return ret;
    }
};