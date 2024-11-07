class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            for (int j = i + i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += isPrime[i];
        }
        return ans;
    }
};