class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int ra = count(s.begin(), s.end(), 'a');
        int ans = min(ra, n - ra);
        int lb = 0;
        for (int i = 0; i < n; i++) {
            lb += s[i] == 'b';
            ra -= s[i] == 'a';
            ans = min(ans, lb + ra);
        }
        return ans;
    }
};