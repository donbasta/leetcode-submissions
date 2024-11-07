class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ord_A(n + 1), ord_B(n + 1), pref(n);
        for (int i = 0; i < n; i++) {
            ord_A[A[i]] = i;
            ord_B[B[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            int both_first_present = max(ord_A[i], ord_B[i]);
            pref[both_first_present]++;
        }
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        return pref;
    }
};