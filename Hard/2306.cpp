class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long n = ideas.size();
        long long ans = n * n;
        vector<int> startsWith(26);
        unordered_map<string, vector<char>> mp;
        for (int i = 0; i < n; i++) {
            startsWith[ideas[i][0] - 'a']++;
            int len = ideas[i].length();
            mp[ideas[i].substr(1, len - 1)].push_back(ideas[i][0]);
        }
        vector<vector<int>> bruh(26, vector<int>(26));
        for (auto e : mp) {
            int tot = e.second.size();
            for (int i = 0; i < tot; i++) {
                for (int j = 0; j < i; j++) {
                    int x = e.second[i], y = e.second[j];
                    if (x > y) swap(x, y);
                    bruh[x - 'a'][y - 'a']++;
                }
            }
        }
        long long sub = 0;
        for (int i = 0; i < n; i++) {
            int len = ideas[i].length();
            long long tmp = 0;
            for (auto e : mp[ideas[i].substr(1, len - 1)]) {
                tmp += startsWith[e - 'a'];
            }
            sub += 2 * tmp - 1;
        }
        long long dbl = 0;
        for (int i = 0; i < 26; i++) {
            dbl += 1ll * startsWith[i] * (startsWith[i] - 1) / 2;
        }
        for (auto e : mp) {
            int tot = e.second.size();
            dbl += (1ll * tot * (tot - 1) / 2);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                int lol = bruh[i][j];
                dbl += 1ll * lol * (lol - 1);
            }
        }
        
        return ans - sub + 2 * dbl;
    }
};