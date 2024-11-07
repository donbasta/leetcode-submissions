class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int lmao = 0;
        int ans = 0;
        int n = gain.size();
        for (int i = 0; i < n; i++) {
            lmao += gain[i];
            ans = max(ans, lmao);
        }
        return ans;
    }
};