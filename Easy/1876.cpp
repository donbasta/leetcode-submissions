class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i <= n - 3; i++) {
            set<char> tmp;
            for (int j = 0; j < 3; j++) tmp.insert(s[i + j]);
            if (tmp.size() == 3) ans++;
        }
        return ans;
    }
};