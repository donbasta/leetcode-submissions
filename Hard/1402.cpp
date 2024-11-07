class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int pre = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (pre + satisfaction[i] >= 0) {
                pre += satisfaction[i];
                ans += pre;
            }
        }
        return ans;
    }
};