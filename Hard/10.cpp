class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        // cout << ns << ' ' << np << '\n';
        
        vector<vector<int>> dp(ns + 1, vector<int>(np + 1, -1));
        
        const function<int(int, int)> rec = [&](int a, int b) {
            if ((a == ns) && (b == np)) return 1;
            if (b == np) return 0;
            if (a == ns) {
                cout << a << ' ' << b << '\n';
                if (b >= np - 1) return 0;
                if (p[b + 1] != '*') return 0;
                return dp[a][b] = rec(a, b + 2);
            }
            // if ((a == ns) || (b == np)) return 0;
            if (dp[a][b] != -1) return dp[a][b];
            if (b < (np - 1)) {
                int ret = 0;
                if (p[b + 1] == '*') {
                    ret = rec(a, b + 2);
                    int i = a;
                    if (p[b] != '.') {
                        while (i < ns && s[i] == p[b]) {
                            ret |= rec(i + 1, b + 2);
                            i++;
                        } 
                    } else {
                        while (i < ns) {
                            ret |= rec(i + 1, b + 2);
                            i++;
                        }   
                    }
                } else {
                    if (p[b] != '.') {
                        ret = (rec(a + 1, b + 1) && (s[a] == p[b]));
                    } else {
                        ret = rec(a + 1, b + 1);
                    }
                }
                return dp[a][b] = ret;
            } else {
                if (p[b] != '.') {
                    return dp[a][b] = ((s[a] == p[b]) && (a == ns - 1));
                } else {
                    return dp[a][b] = (a == ns - 1);
                }
            }
        };
        
        return rec(0, 0);
    }
};