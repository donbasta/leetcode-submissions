class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        vector<pair<int, int>> comp;
        char cur = s[0];
        int len = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == cur) len++;
            else {
                comp.emplace_back(len, cur - '0');
                cur = s[i];
                len = 1;
            }
        }
        comp.emplace_back(len, cur - '0');
        int sz = comp.size();
        for (int i = 0; i < sz - 1; i++) {
            if (comp[i].second == 1) continue;
            ans = max(ans, 2 * min(comp[i].first, comp[i + 1].first));
        }
        return ans;
    }
};