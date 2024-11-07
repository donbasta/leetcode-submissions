class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        vector<int> sep;
        int n = word.size();
        sep.push_back(0);
        for (int i = 1; i < n; i++) {
            if (abs(word[i] - word[i - 1]) > 2) {
                sep.push_back(i);
            }
        }
        sep.push_back(n);
        int sz = sep.size();
        int ans = 0;
        for (int i = 0; i < sz - 1; i++) {
            vector<vector<int>> mp;
            vector<int> cur(26);
            mp.push_back(cur);
            for (int j = sep[i]; j <= sep[i + 1] - 1; j++) {
                cur[word[j] - 'a']++;
                bool stop = false;
                for (int t = (int)mp.size() - k; t >= max(0, (int)mp.size() - 26 * k); t -= k) {
                    bool ok = true;
                    for (int u = 0; u < 26; u++) {
                        int cek = cur[u] - mp[t][u];
                        if (cek > k) {
                            stop = true;
                        }
                        if (cek != 0 && cek != k) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) ans++;
                    if (stop) break;
                }
                mp.push_back(cur);
            }
        }
        return ans;
    }
};