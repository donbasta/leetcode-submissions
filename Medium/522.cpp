class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;


        auto is_subseq = [&](const string& x, const string& y) -> bool {
            int ptr = 0;
            for (int i = 0; i < (int)x.length(); i++) {
                while (ptr < (int)y.length() && y[ptr] != x[i]) {
                    ++ptr;
                }
                if (ptr == (int)y.length()) return false;
                ++ptr;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (is_subseq(strs[i], strs[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};