class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string ss = s;
        reverse(ss.begin(), ss.end());
        string s2 = s; s2.push_back('#'); s2 += ss;
        
        const auto LCP = [&](string S) -> vector<int> {
            vector<int> ret(S.length());
            for (int i = 1; i < S.length(); i++) {
                int j = ret[i - 1];
                while (j && S[i] != S[j]) {
                    j = ret[j - 1];
                }
                if (S[i] == S[j]) {
                    j++;
                }
                ret[i] = j;
            }
            return ret;
        };
        
        vector<int> lcp = LCP(s2);
        int longestPrefixPalindrome = lcp.back();
        string rem = s.substr(longestPrefixPalindrome, n - longestPrefixPalindrome);
        reverse(rem.begin(), rem.end());
        rem += s;
        return rem;
    }
};