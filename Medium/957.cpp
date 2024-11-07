class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<vector<int>, int> mp;
        vector<vector<int>> ve;
        mp[cells] = 0;
        ve.push_back(cells);
        for (int i = 1; i <= n; i++) {
            vector<int> tmp(8);
            for (int j = 1; j < 7; j++) {
                if (cells[j - 1] == cells[j + 1]) tmp[j] = 1;
            }
            if (mp.count(tmp)) {
                int prv = mp[tmp];
                int cyc = i - prv;
                int sisa = (n - i) % cyc;
                return ve[sisa + prv];
                //prv --> i repeat
                //i+cyc, ..., i+k*cyc+sisa
            } else {
                cells = tmp;
                mp[cells] = i;
                ve.push_back(cells);
            }
        }
        return cells;
    }
};