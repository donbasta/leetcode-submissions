class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        reverse(properties.begin(), properties.end());
        int mx = 0;
        int cur = properties[0][0];
        int n = properties.size();
        int ans = 0;
        vector<int> tmp = {properties[0][1]};
        for (int i = 1; i < n; i++) {
            if (properties[i][0] != cur) {
                for (auto e : tmp) {
                    if (e < mx) {
                        ans++;
                    }
                }
                for (auto e : tmp) {
                    mx = max(mx, e);
                }

                cur = properties[i][0];
                tmp.clear();
                tmp.emplace_back(properties[i][1]);
            } else {
                tmp.emplace_back(properties[i][1]);
            }
        }
        for (auto e : tmp) {
            if (e < mx) {
                ans++;
            }
        }
        return ans;
    }
};