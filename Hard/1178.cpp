class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> cnt;
        for (auto w : words) {
            int x = 0;
            for (auto c : w) {
                x = x | (1 << (c - 'a'));
            }
            cnt[x]++;
        }
        vector<int> ret;
        for (auto p : puzzles) {
            int lol = 0;
            string cp = p;
            sort(cp.begin(), cp.end());
            cp.resize(unique(cp.begin(), cp.end()) - cp.begin());
            vector<int> tmp;
            for (auto c : cp) {
                if (c == p[0]) continue;
                tmp.push_back(c);
            }
            int sz = tmp.size();
            int aw = (1 << (p[0] - 'a'));
            for (int i = 0; i < (1 << sz); i++) {
                int msk = aw;
                for (int j = 0; j < sz; j++) {
                    if ((i >> j) & 1) msk = msk | (1 << (tmp[j] - 'a'));
                }
                if (cnt.count(msk)) {
                    lol += cnt[msk];
                }
            }
            ret.push_back(lol);
        }
        return ret;
    }
};