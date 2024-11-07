class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ret[n + 1];
        ret[1] = {"0", "1"};
        for (int i = 2; i <= n; i++) {
            for (auto s : ret[i - 1]) {
                if (s.back() == '0') {
                    s += '1';
                    ret[i].push_back(s);
                } else {
                    s += '0';
                    ret[i].push_back(s);
                    s.pop_back();
                    s += '1';
                    ret[i].push_back(s);
                }
            }
        }
        return ret[n];
    }
};