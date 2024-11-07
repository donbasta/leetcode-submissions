class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> L(n, -1), R(n, -1);
        L[0] = 0;
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) L[i] = L[i - 1];
            else L[i] = i;
        }
        R[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) R[i] = R[i + 1];
            else R[i] = i;
        }
        vector<int> ve;
        for (int i = 0; i < n; i++) {
            if (L[i] <= i - time && R[i] >= i + time) ve.push_back(i);
        }
        return ve;
    }
};