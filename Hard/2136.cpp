class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> ve;
        int n = plantTime.size();
        for (int i = 0; i < n; i++) {
            ve.emplace_back(growTime[i], plantTime[i]);
        }
        sort(ve.begin(), ve.end(), greater<>());
        int mx = 0;
        int pre = 0;
        for (int i = 0; i < n; i++) {\
            pre += ve[i].second;
            mx = max(mx, pre + ve[i].first);
        }
        return mx;
    }
};