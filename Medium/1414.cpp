class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        using ll = long long;
        vector<ll> fibo;
        fibo.push_back(1);
        fibo.push_back(2);
        while (fibo.back() < k) {
            fibo.push_back(fibo.back() + fibo[fibo.size() - 2]);
        }
        int itr = fibo.size() - 1;
        int ans = 0;
        while (k > 0) {
            while (itr > 0 && fibo[itr] > k) itr--;
            assert (itr >= 0);
            k -= fibo[itr];
            ans++;
        }
        return ans;
    }
};