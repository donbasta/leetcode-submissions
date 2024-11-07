class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sisa = 0;
        sort(batteries.begin(), batteries.end(), greater<>());
        for (int i = n; i < batteries.size(); i++) sisa += batteries[i];
        for (int i = n - 1; i >= 1; i--) {
            if (sisa >= 1ll * (batteries[i - 1] - batteries[i]) * (n - i)) {
                sisa -= 1ll * (batteries[i - 1] - batteries[i]) * (n - i);
            } else {
                return batteries[i] + sisa / (n - i);
            }
        }
        return batteries[0] + sisa / n;
    }
};