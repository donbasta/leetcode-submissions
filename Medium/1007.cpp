class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        int n = tops.size();
        for (int i = 1; i <= 6; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += (tops[j] == i) || (bottoms[j] == i);
            }
            if (cnt < n) continue;
            int at = 0, bw = 0;
            for (int j = 0; j < n; j++) {
                at += tops[j] != i;
            }
            for (int j = 0; j < n; j++) {
                bw += bottoms[j] != i;
            }
            ans = min(ans, at);
            ans = min(ans, bw);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};