class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ret;
        int len = queries[0].length();
        for (auto q : queries) {
            bool ok = false;
            for (auto d : dictionary) {
                int beda = 0;
                for (int i = 0; i < len; i++) beda += q[i] != d[i];
                if (beda <= 2) {
                    ok = true;
                    break;
                }
            }
            if (ok) ret.push_back(q);
        }
        return ret;
    }
};