class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        vector<string> ret;
        auto huruf = [&](char c) -> bool {
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        };
        auto ubah = [&](char c) -> char {
            if (c >= 'a' && c <= 'z') return c + 'A' - 'a';
            return c + 'a' - 'A';
        };
        for (int i = 0; i < (1 << n); i++) {
            string tmp = s;
            bool cant = false;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (!huruf(s[j])) {
                        cant = true;
                        break;
                    } else {
                        tmp[j] = ubah(tmp[j]);
                    }
                }
            }
            if (cant) continue;
            ret.push_back(tmp);
        }
        return ret;
    }
};