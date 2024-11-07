class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        
        vector<long long> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        const function<long long(int, int)> getScore = [&](int le, int ri) -> long long {
            long long sum = pre[ri] - (le ? pre[le - 1] : 0);
            return sum * (ri - le + 1);
        };

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int le = i, ri = n - 1;
            int bat = -1;
            while (le <= ri) {
                int mid = (le + ri) >> 1;
                long long sc = getScore(i, mid);
                if (sc >= k) {
                    ri = mid - 1;
                } else {
                    bat = mid;
                    le = mid + 1;
                }
            }
            if (bat == -1) continue;
            ans += (bat - i + 1);
        }

        return ans;
    }
};