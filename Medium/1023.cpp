class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        int sz = pattern.size();

        auto upper = [&](char c) -> bool {
            return c >= 'A' && c <= 'Z';
        };

        for (auto q : queries) {
            int i1 = 0, i2 = 0;
            bool ok = true;
            while (i2 < sz) {
                while (i1 < (int)q.size() && q[i1] != pattern[i2]) {
                    if (upper(q[i1])) {
                        ok = false;
                        break;
                    }
                    i1++;
                }
                if (i1 == (int)q.size()) {
                    ok = false;
                }
                if (!ok) break;
                i1++;
                i2++;
            }
            while (i1 < (int)q.size()) {
                if (upper(q[i1])) {
                    ok = false;
                    break;
                }
                i1++;
            }
            ret.push_back(ok);
        }
        return ret;
    }
};