class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<vector<int>> ve(3);
        int sum = 0;
        for (auto e : digits) {
            ve[e % 3].push_back(e);
            sum += e;
        }
        string ret;
        sort(digits.begin(), digits.end());
        if (sum % 3 == 0) {
            for (auto d : digits) {
                ret.push_back((char)(d + '0'));
            }
        } else if (sum % 3 == 1) {
            if (!ve[1].empty()) {
                sort(ve[1].begin(), ve[1].end());
                int idx = 0;
                for (auto d : digits) {
                    if (idx < 1 && d == ve[1][idx]) idx++;
                    else ret.push_back((char)(d + '0'));
                }
            } else if (ve[2].size() >= 2) {
                sort(ve[2].begin(), ve[2].end());
                int idx = 0;
                for (auto d : digits) {
                    if (idx < 2 && d == ve[2][idx]) idx++;
                    else ret.push_back((char)(d + '0'));
                }
            } 
        } else {
            if (!ve[2].empty()) {
                sort(ve[2].begin(), ve[2].end());
                int idx = 0;
                for (auto d : digits) {
                    if (idx < 1 && d == ve[2][idx]) idx++;
                    else ret.push_back((char)(d + '0'));
                }
            } else if (ve[1].size() >= 1) {
                sort(ve[1].begin(), ve[1].end());
                int idx = 0;
                for (auto d : digits) {
                    if (idx < 2 && d == ve[1][idx]) idx++;
                    else ret.push_back((char)(d + '0'));
                }
            }
        }
        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};