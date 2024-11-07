class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes;
        const int N = 2000;
        bool pr[N + 5];
        memset(pr, 1, sizeof(pr)); 
        for (int i = 2; i <= N; i++) {
            if (!pr[i]) continue;
            primes.push_back(i);
            for (int j = i + i; j <= N; j += i) {
                pr[j] = false;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            int L = nums[i + 1];
            if (nums[i] < L) continue;
            // nums[i] - p <= L - 1
            // p >= nums[i] - L + 1
            int idx = lower_bound(primes.begin(), primes.end(), nums[i] - L + 1) - primes.begin();
            if (idx == (int)primes.size() || primes[idx] >= nums[i]) return false;
            nums[i] -= primes[idx];
            // cout << i << ' ' << nums[i] << '\n';
        }
        return true;
    }
};