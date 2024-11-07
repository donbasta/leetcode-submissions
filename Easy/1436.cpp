class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> se, out;
        for (auto p : paths) {
            out.insert(p[0]);
            se.insert(p[0]);
            se.insert(p[1]);
        }
        for (auto e : se) {
            if (!out.count(e)) return e;
        }
        return "LOL";
    }
};