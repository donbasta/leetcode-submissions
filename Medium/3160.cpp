class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> mp;
        map<int, int> col;
        vector<int> ret;
        for (auto q : queries) {
            int a = q[0], b = q[1];
            int prv = (col.count(a) ? col[a] : -1);
            if (prv != -1) {
                mp[prv]--;
                if (mp[prv] == 0) {
                    mp.erase(prv);
                }
            }
            col[a] = b;
            mp[b]++;
            ret.push_back((int)mp.size());
        }
        return ret;
    }
};