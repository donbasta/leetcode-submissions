class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int lo = 1, hi = n;
        int ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            long long sum = 0;
            multiset<int> tmp;
            for (int i = 0; i < mid - 1; i++) {
                tmp.insert(chargeTimes[i]);
                sum += runningCosts[i];
            }
            long long mn = 1e18;
            for (int i = mid - 1; i < n; i++) {
                tmp.insert(chargeTimes[i]);
                sum += runningCosts[i];
                mn = min(mn, sum * mid + *tmp.rbegin());
                if (i < n - 1) {
                    tmp.erase(tmp.find(chargeTimes[i - mid + 1]));
                    sum -= runningCosts[i - mid + 1];
                }
            }
            if (mn <= budget) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};