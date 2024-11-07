class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> lmao;
        for (auto w : words) {
            int n = w.length();
            for (int i = 0; i < n; i++) {
                string tmp;
                for (int j = i; j < n; j++) {
                    tmp += w[j];
                    if (i != 0 || j != n - 1) lmao.insert(tmp);
                }
            }
        }
        vector<string> ve;
        for (auto w : words) {
            if (lmao.count(w)) ve.push_back(w);
        }
        return ve;
    }
};