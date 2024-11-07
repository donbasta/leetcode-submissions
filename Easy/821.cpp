class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                pos.emplace_back(i);
            }
        }
        int sz = pos.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int k = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
            int tmp = INT_MAX;
            if (k < sz) {
                tmp = min(tmp, pos[k] - i);
            }
            if (k > 0) {
                tmp = min(tmp, i - pos[k - 1]);
            }
            ans[i] = tmp;
        }
        return ans;
    }
};