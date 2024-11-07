class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string sn = to_string(n);
        vector<int> cnt(10);
        for (auto c : sn) cnt[c - '0']++;
        for (int i = 0; i < 30; i++) {
            string cek = to_string(1 << i);
            if (cek.length() != sn.length()) {
                continue;
            }
            vector<int> tmp(10);
            for (auto c : cek) tmp[c - '0']++;
            if (cnt == tmp) return true;
        }
        return false;
    }
};