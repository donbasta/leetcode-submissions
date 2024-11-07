class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26);
        int n = s.length();
        vector<pair<int, int>> ve;
        for (auto c : s) cnt[c - 'a']++;
        for (int i = 0; i < 26; i++) ve.emplace_back(cnt[i], i);
        sort(ve.begin(), ve.end(), greater<>());
        string ans(n, '.');
        int idx = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < ve[i].first; j++) {
                ans[idx] = (char)(ve[i].second + 'a');
                idx += 2;
                if (idx >= n) idx = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            if (ans[i] == ans[i - 1]) return "";
        }
        return ans;
    }
};