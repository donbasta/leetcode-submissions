
class Solution {
public:
    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    vector<int> manacher(string s) {
        string t;
        for (auto c: s) {
            t += string("#") + c;
        }
        return manacher_odd(t + "#");
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, vector<int>> cnt, cnt_rev;
        vector<vector<int>> ret;
        int n = words.size();
        bool ada[n][n];
        memset(ada, 0, sizeof(ada));
        for (int i = 0; i < n; i++) {
            string tmp = words[i];
            cnt[tmp].push_back(i);
            reverse(tmp.begin(), tmp.end());
            cnt_rev[tmp].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vector<int> pal = manacher(words[i]);
            int len = words[i].length();
            string cur = "";
            for (int j = len; j >= 0; j--) {
                if (cnt.count(cur) && (pal[j] >= j + 1)) {
                    for (auto x : cnt[cur]) if (x != i && !ada[x][i]) ret.push_back(vector<int>{x, i}), ada[x][i] = true;
                }
                if (j > 0) cur += words[i][j - 1];
            }
            cur = "";
            for (int j = 0; j <= len; j++) {
                if (cnt_rev.count(cur) && (pal[len + j] >= len + 1 - j)) {
                    for (auto x : cnt_rev[cur]) if (x != i && !ada[i][x]) ret.push_back(vector<int>{i, x}), ada[i][x] = true;
                }
                if (j < len) cur += words[i][j];
            }
        }
        return ret;
    }
};