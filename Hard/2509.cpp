class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ret;
        for (auto q : queries) {
            int a = q[0], b = q[1];
            unordered_map<int, int> cnt;
            while (a) {
                cnt[a]++, a >>= 1;
            }
            while (b) {
                cnt[b]++, b >>= 1;
            }
            int lca = 1;
            for (auto e : cnt) {
                if (e.second == 2) {
                    lca = max(lca, e.first);
                }
            }
            a = q[0], b = q[1];
            int step = 0;
            while (a > lca) {
                step++;
                a >>= 1;
            }
            while (b > lca) {
                step++;
                b >>= 1;
            }
            ret.push_back(step + 1);
        }
        return ret;
    }
};