class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> ve(3);
        ve.emplace_back(a, 'a');
        ve.emplace_back(b, 'b');
        ve.emplace_back(c, 'c');
        sort(ve.begin(), ve.end(), greater<>());
        if (ve[0].first > 2 * (ve[1].first + ve[2].first + 1)) {
            ve[0].first = 2 * (ve[1].first + ve[2].first + 1);
        }
        string ret;
        int xx = ve[1].first, cx = ve[1].second, yy = ve[2].first, cy = ve[2].second;
        if (ve[1].first + ve[2].first > ve[0].first) {
            for (int i = 0; i < ve[0].first; i++) {
                ret.push_back(ve[0].second);
                if (xx > 0) {
                    ret.push_back(cx);
                    xx--;
                } else if (yy > 0) {
                    ret.push_back(cy);
                    yy--;
                }
                if (i < ve[1].first + ve[2].first - ve[0].first) {
                    if (xx > 0) {
                        ret.push_back(cx);
                        xx--;
                    } else if (yy > 0) {
                        ret.push_back(cy);
                        yy--;
                    }
                }
            }
        } else {
            int lmao = ve[0].first;
            for (int i = 0; i < ve[1].first + ve[2].first; i++) {
                ret.push_back(ve[0].second);
                lmao--;
                if (i < ve[0].first - ve[1].first - ve[2].first) {
                    ret.push_back(ve[0].second);
                    lmao--;
                }
                if (xx > 0) {
                    ret.push_back(cx);
                    xx--;
                } else {
                    ret.push_back(cy);
                    yy--;
                }
            }
            while (lmao--) ret.push_back(ve[0].second);
        }
        return ret;
    }
};