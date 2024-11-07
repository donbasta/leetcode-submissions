class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m1 = s1.length(), m2 = s2.length();
        vector<pair<int, int>> dp(m2); //jump, ending
        for (int i = 0; i < m2; i++) { //start from index i of s2
            int cur = i;
            int lompat = 0;
            for (int j = 0; j < m1; j++) {
                if (s1[j] == s2[cur]) {
                    if (cur == m2 - 1) {
                        cur = 0;
                        lompat++;
                    } else {
                        cur++;
                    }
                }
            }
            dp[i] = make_pair(lompat, cur);
        }
        int now = 0;
        int a = 0;
        for (int i = 0; i < n1; i++) {
            auto lmao = dp[now];
            a += lmao.first;
            now = lmao.second;
        }
        return (a / n2);
    }
};