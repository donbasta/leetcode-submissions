class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e7;
        int n = dist.size();
        int ans = -1; 
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long tmp = 0;
            for (int i = 0; i < n - 1; i++) {
                tmp += (dist[i] + mid - 1) / mid;
            }
            double lmao = (double) (tmp);
            lmao += (double) (dist[n - 1]) / (double) mid;
            if (lmao <= hour) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};