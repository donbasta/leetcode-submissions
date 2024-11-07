class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26);
        iota(cost.begin(), cost.end(), 1);
        for (int i = 0; i < (int)chars.size(); i++) {
            cost[chars[i] - 'a'] = vals[i];
        }

        int n = s.length();
        int cur = 0;
        int mn = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cur += cost[s[i] - 'a'];
            ans = max(ans, cur - mn);
            mn = min(mn, cur);
        }
        return ans;
    }
};