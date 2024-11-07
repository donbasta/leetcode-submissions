class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, score = 0;
        int ans = 0;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                l++;
                score++;
                ans = max(ans, score);
            } else if (score >= 1) {
                power += tokens[r];
                r--;
                score--;
            } else {
                break;
            }
        }
        return ans;
    }
};