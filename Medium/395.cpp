class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        vector<vector<int>> le(26, vector<int>(n, -1));
        vector<vector<int>> pre(26, vector<int>(n));
        vector<vector<int>> mx(26, vector<int>(n, -1));
        pre[s[0] - 'a'][0]++;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) pre[j][i] = pre[j][i - 1];
            pre[s[i] - 'a'][i]++;
        }
        le[s[0] - 'a'][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) le[j][i] = le[j][i - 1];
            le[s[i] - 'a'][i] = i;
        }
        if (k == 1) mx[s[0] - 'a'][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (pre[j][i] < k) continue;
                int u = lower_bound(pre[j].begin(), pre[j].end(), pre[j][i] - k + 1) - pre[j].begin();
                mx[j][i] = u;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> tmp;
            for (int j = 0; j < 26; j++) {
                tmp.emplace_back(le[j][i], mx[j][i]);
            }
            sort(tmp.begin(), tmp.end(), greater<>());
            int R = tmp[0].first, L = tmp[0].second;
            if (L == -1) continue;
            for (int j = 1; j < 26; j++) {
                if (tmp[j].first == -1) {
                    ans = max(ans, i + 1);
                    break;
                }
                if (tmp[j].first < L) {
                    ans = max(ans, i - tmp[j].first);
                }
                L = min(L, tmp[j].second);
                if (L == -1) break;
            }
        }
        return ans;
    }
};