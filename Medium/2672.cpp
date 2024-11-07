class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        set<int> se;
        vector<int> ve(n);
        // for (int i = 0; i < n - 1; i++) {
        //     se.insert(i);
        // }
        vector<int> ret;
        for (auto q : queries) {
            int id = q[0], co = q[1];
            if (id > 0 && ve[id - 1] == ve[id]) {
                se.erase(id - 1);
            }
            if (id < n - 1 && ve[id] == ve[id + 1]) {
                se.erase(id);
            }
            ve[id] = co;
            if (id > 0 && ve[id - 1] == ve[id]) {
                se.insert(id - 1);
            }
            if (id < n - 1 && ve[id] == ve[id + 1]) {
                se.insert(id);
            }
            ret.emplace_back(se.size());
        }
        return ret;
    }
};