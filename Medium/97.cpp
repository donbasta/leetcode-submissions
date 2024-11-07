class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n3 != n1 + n2) return false;
        if (n1 == 0) return s2 == s3;
        if (n2 == 0) return s1 == s3;
        int DP[n1][n2][2];
        memset(DP, -1, sizeof(DP));

        const function<int(int, int, int)> dp = [&](int i1, int i2, int p) -> int {
            if (i1 == n1) {
                if (p == 0) return false;
                if (p == 1) return s2.substr(i2, n2 - i2) == s3.substr(i2 + n1, n3 - i2 - n1);
            }
            if (i2 == n2) {
                if (p == 1) return false;
                if (p == 0) return s1.substr(i1, n1 - i1) == s3.substr(i1 + n2, n3 - i1 - n2);
            }
            if (DP[i1][i2][p] != -1) return DP[i1][i2][p];
            bool ret = false;
            if (p == 0) {
                int start = i1;
                while (start < n1 && s1[start] == s3[start + i2]) {
                    ret = (ret || dp(start + 1, i2, 1 - p));
                    start++;
                }
            } else if (p == 1) {
                int start = i2;
                while (start < n2 && s2[start] == s3[start + i1]) {
                    ret = (ret || dp(i1, start + 1, 1 - p));
                    start++;
                }
            }
            return DP[i1][i2][p] = ret;
        }; 

        return (dp(0, 0, 0) || dp(0, 0, 1));
    }
};