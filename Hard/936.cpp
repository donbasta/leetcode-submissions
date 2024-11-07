class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        string tmp = target;
        vector<int> ret;
        int s = stamp.length(), t = target.length();
        auto cek = [&](int x) {
            int ksg = 0;
            for (int i = x; i < x + s; i++) {
                if (tmp[i] == 'A') {ksg++; continue;}
                if (tmp[i] != stamp[i - x]) return false;
            }
            if (ksg == s) return false;
            return true;
        };
        while (true) {
            int x = 0;
            for (int i = 0; i <= t - s; i++) {
                if (cek(i)) {
                    x++;
                    ret.push_back(i);
                    for (int j = i; j < i + s; j++) tmp[j] = 'A';
                }
            }
            if (x == 0) {
                break;
            }
        }
        for (auto c : tmp) {
            if (c != 'A') return vector<int>{};
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};