class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.length();
        int sz = indices.size();
        vector<int> id(sz);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int a, int b) -> bool {
            return indices[a] < indices[b];
        });
        vector<bool> ok(sz);
        for (int i = 0; i < sz; i++) {
            int len = sources[id[i]].length();
            ok[i] = (indices[id[i]] <= n - len && s.substr(indices[id[i]], len) == sources[id[i]]);
        }
        string ret;
        int cur = 0;
        for (int i = 0; i < sz; i++) {
            if (!ok[i]) continue;
            ret += s.substr(cur, indices[id[i]] - cur);
            ret += targets[id[i]];
            cur = indices[id[i]] + sources[id[i]].length();
        }
        if (cur < n) {
            ret += s.substr(cur, n - cur);
        }
        return ret;
    }
};