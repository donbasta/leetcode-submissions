class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> sz(30);
        for (auto c : candidates) {
            for (int i = 0; i < 30; i++) {
                if ((c >> i) & 1) {
                    sz[i]++;
                }
            }
        }
        return *max_element(sz.begin(), sz.end());
    }
};