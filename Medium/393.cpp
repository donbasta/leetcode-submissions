class Solution {
public:
    string bin(int x) {
        string ret;
        for (int i = 7; i >= 0; i--) {
            ret.push_back((char)('0' + ((x >> i) & 1)));
        }
        return ret;
    }
    bool validUtf8(vector<int>& data) {
        for (auto& x : data) {
            int prf = 0;
            for (auto c : bin(x)) {
                if (c == '0') break;
                prf++;
            }
            x = prf;
        }
        int type = -1;
        int cnt = 0;
        for (auto x : data) {
            // cout << x << ' ';
            if (x > 4) return false;
            if (type == -1) {
                if (x == 1) return false;
                if (x >= 2) {
                    type = x;
                }
            } else {
                if (x != 1) return false;
                cnt++;
                if (cnt == type - 1) {
                    type = -1;
                    cnt = 0;
                }
            }
        }
        return type == -1;
    }
};