class Solution {
public:
    int maxProduct(vector<int>& nums) {
        set<int> negatives, positives;
        positives.insert(1);
        int cur = 1;
        int ans = INT_MIN;
        for (auto e : nums) {
            if (e == 0) {
                ans = max(ans, 0);
                negatives.clear(), positives.clear();
                positives.insert(1);
                cur = 1;
                continue;
            }
            cur *= e;
            if (cur < 0) {
                if (!negatives.empty()) {
                    ans = max(ans, cur / *negatives.rbegin());
                } else { 
                    ans = max(ans, cur / *positives.rbegin());
                }
                negatives.insert(cur);
            } else if (cur > 0) {
                ans = max(ans, cur);
                positives.insert(cur);
            }
        }
        return ans;
    }
};