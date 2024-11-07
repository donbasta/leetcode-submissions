class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> A = heights;
        sort(A.begin(), A.end());
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < n; i++) ans += heights[i] != A[i];
        return ans;
    }
};