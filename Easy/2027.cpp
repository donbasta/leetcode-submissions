class Solution {
public:
    int minimumMoves(string s) {
        int i1 = 0;
        int ans = 0;
        while (i1 < s.length()) {
            if (s[i1] == 'X') {
                ans++, i1 += 3;
            } else {
                i1++;
            }
        }
        return ans;
    }
};