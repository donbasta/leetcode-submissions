class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<int>> c1(5), c2(7);
        for (int i = 0; i <= 11; i++) {
            c1[__builtin_popcount(i)].push_back(i);
        }
        for (int i = 0; i <= 59; i++) {
            c2[__builtin_popcount(i)].push_back(i);
        }

        vector<string> ret;
        for (int i = 0; i <= 4; i++) {
            for (int j = 0; j <= 6; j++) {
                if (i + j != turnedOn) continue;
                for (auto x : c1[i]) {
                    for (auto y : c2[j]) {
                        string hh = to_string(x);
                        string mm = to_string(y);
                        if (mm.length() == 1) mm = "0" + mm;
                        ret.push_back(hh + ":" + mm);
                    }
                }
            }
        }
        return ret;
    }
};