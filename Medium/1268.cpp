class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, set<string>> se;
        for (auto e : products) {
            int len = e.length();
            string cur;
            for (int i = 1; i <= len; i++) {
                cur.push_back(e[i - 1]);
                se[cur].insert(e);
            }
        }
        vector<vector<string>> res;
        string tmp;
        for (auto e : searchWord) {
            tmp.push_back(e);
            vector<string> lmao;
            if (!se.count(tmp)) {
                res.push_back(lmao);
                continue;
            }
            for (auto ee : se[tmp]) {
                lmao.push_back(ee);
                if (lmao.size() >= 3) break;
            }
            res.push_back(lmao);
        }
        return res;
    }
};