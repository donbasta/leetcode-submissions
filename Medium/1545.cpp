class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            string cs = s;
            for (auto& c : cs) if (c == '1') c = '0'; else c = '1';
            reverse(cs.begin(), cs.end());
            s = s + "1" + cs;
        }
        return s[k - 1];
    }
};