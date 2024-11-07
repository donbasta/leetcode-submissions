class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {   
        int n = arr1.size();
        long long m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN, m4 = INT_MIN;
        int ans = abs(arr1[1] - arr1[0]) + abs(arr2[1] - arr2[0]) + 1;
        for (int i = 0; i < 2; i++) {
            m1 = max(m1, 1ll * arr1[i] + arr2[i] - i);
            m2 = max(m2, 1ll * arr1[i] - arr2[i] - i);
            m3 = max(m3, 1ll * -arr1[i] + arr2[i] - i);
            m4 = max(m4, 1ll * -arr1[i] - arr2[i] - i);
        }
        for (int i = 2; i < n; i++) {
            ans = max(1ll * ans, m1 + i - arr1[i] - arr2[i]);
            ans = max(1ll * ans, m2 + i - arr1[i] + arr2[i]);
            ans = max(1ll * ans, m3 + i + arr1[i] - arr2[i]);
            ans = max(1ll * ans, m4 + i + arr1[i] + arr2[i]);

            m1 = max(m1, 1ll * arr1[i] + arr2[i] - i);
            m2 = max(m2, 1ll * arr1[i] - arr2[i] - i);
            m3 = max(m3, 1ll * -arr1[i] + arr2[i] - i);
            m4 = max(m4, 1ll * -arr1[i] - arr2[i] - i);
        }
        return ans;
    }
};