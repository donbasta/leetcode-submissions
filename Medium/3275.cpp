class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        multiset<int> se;
        vector<int> res;
        for (auto q : queries) {
            int dis = abs(q[0]) + abs(q[1]);
            if (se.size() < k) se.insert(dis);
            else {
                if (dis < *se.rbegin()) {
                    se.erase(se.find(*se.rbegin()));
                    se.insert(dis);
                }
            }
            if (se.size() < k) {
                res.push_back(-1);
            } else {
                res.push_back(*se.rbegin());
            }
        }
        return res;
    }
};