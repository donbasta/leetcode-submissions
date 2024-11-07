class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<long long> po;
        for (auto e : potions) po.push_back(e);
        sort(po.begin(), po.end());
        vector<int> ve;
        int n = po.size();
        for (auto e : spells) {
            long long need = (success + e - 1) / e;
            int fi = lower_bound(po.begin(), po.end(), need) - po.begin();
            ve.push_back(n - fi);
        }
        return ve;
    }
};