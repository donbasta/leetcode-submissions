class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(26);
            cnt[s[i] - 'a']++;
            set<pair<int, int>> se;
            se.emplace(cnt[s[i] - 'a'], s[i] - 'a');
            for (int j = i + 1; j < n; j++) {
                se.erase(make_pair(cnt[s[j] - 'a'], s[j] - 'a'));
                cnt[s[j] - 'a']++;
                se.emplace(cnt[s[j] - 'a'], s[j] - 'a');
                ans += (se.rbegin()->first - se.begin()->first);
            }
        }
        return ans;
    }
};