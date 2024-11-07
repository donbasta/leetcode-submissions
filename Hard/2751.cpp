class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
            return positions[a] < positions[b];
        });
        vector<pair<int, int>> L, rem;
        for (int i = n - 1; i >= 0; i--) {
            if (directions[idx[i]] == 'L') {
                L.emplace_back(idx[i], healths[idx[i]]);
            } else {
                int cur = healths[idx[i]];
                bool survive = true;
                while (!L.empty()) {
                    if (cur > L.back().second) {
                        L.pop_back();
                        cur--;
                    } else if (cur == L.back().second) {
                        L.pop_back();
                        survive = false;
                        break;
                    } else {
                        L.back().second--;
                        survive = false;
                        break;
                    }
                }
                if (survive) {
                    assert (cur > 0);
                    rem.emplace_back(idx[i], cur);
                }
            }
        }
        for (auto le : L) {
            rem.emplace_back(le);
        }
        sort(rem.begin(), rem.end());
        vector<int> ret;
        for (auto r : rem) {
            ret.push_back(r.second);
        }
        return ret;
    }
};