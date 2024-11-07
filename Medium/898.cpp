class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> se;
        int n = arr.size();
        vector<vector<int>> pos(30);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if ((arr[i] >> j) & 1) pos[j].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            se.insert(arr[i]);
            map<int, int> tmp;
            for (int j = 0; j < 30; j++) {
                if ((arr[i] >> j) & 1) continue;
                int idx = upper_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
                if (idx == (int)pos[j].size()) continue;
                tmp[pos[j][idx]] ^= (1 << j);
            }
            int lmao = arr[i];
            for (auto t : tmp) {
                se.insert(lmao ^ t.second);
                lmao ^= t.second;
            }
        }

        // for (auto s : se) cout << s << ' ';
        return (int)se.size();
    }
};