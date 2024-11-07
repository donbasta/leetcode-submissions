class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        int n = fc.size();
        map<string, int> id;
        int sz = 0;
        for (int i = 0; i < n; i++) {
            for (auto c : fc[i]) {
                if (!id.count(c)) {
                    id[c] = sz++;
                }
            }
        }
        bitset<50000> bt[n];
        for (int i = 0; i < n; i++) {
            for (auto c : fc[i]) {
                bt[i][id[c]] = 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if ((bt[i] | bt[j]) == bt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};