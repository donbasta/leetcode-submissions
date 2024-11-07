class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ret;
        int n = height.size();
        for (int i = 1; i < n; i++) {
            if (height[i - 1] > threshold) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};