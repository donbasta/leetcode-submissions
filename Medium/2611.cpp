class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> ve;
        for (int i = 0; i < n; i++) {
            ve.push_back(reward1[i] - reward2[i]);
        }
        sort(ve.begin(), ve.end());
        int ans = accumulate(reward2.begin(), reward2.end(), 0);
        for (int i = n - 1; i >= n - k; i--) {
            ans += ve[i];
        }
        return ans;
    }
};