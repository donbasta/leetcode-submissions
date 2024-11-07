class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        vector<vector<long long>> tot(n, vector<long long>(40));
        vector<vector<int>> nx(n, vector<int>(40));
        for (int i = 0; i < n; i++) nx[i][0] = receiver[i];
        for (int i = 1; i < 40; i++) {
            for (int j = 0; j < n; j++) {
                nx[j][i] = nx[nx[j][i - 1]][i - 1];
            }
        }
        for (int i = 0; i < n; i++) tot[i][0] = i;
        for (int i = 1; i < 40; i++) {
            for (int j = 0; j < n; j++) {
                tot[j][i] = tot[j][i - 1] + tot[nx[j][i - 1]][i - 1];
            }
        }
        long long ans = 0;
        const function<long long(int, long long)> get_tot = [&](int idx, long long steps) -> long long {
            long long ret = 0;
            int cur = idx;
            for (int i = 39; i >= 0; i--) {
                if ((steps >> i) & 1) {
                    ret += tot[cur][i];
                    cur = nx[cur][i];
                }
            }
            ret += cur;
            return ret;
        };
        for (int i = 0; i < n; i++) {
            ans = max(ans, get_tot(i, k));
        }
        return ans;
        
    }
};