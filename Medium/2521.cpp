class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primes;
        for (auto e : nums) {
            for (int i = 2; i * i <= e; i++) {
                if (e % i == 0) {
                    primes.insert(i);
                    while (e % i == 0) e /= i;
                }
            }
            if (e > 1) primes.insert(e);
        }
        return primes.size();
    }
};