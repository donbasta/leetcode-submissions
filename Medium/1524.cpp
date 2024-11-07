class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, cur = 0;
        int MOD = 1e9 + 7;
        long long ans = 0;
        for(auto i : arr) {
            cur += i;
            if(cur & 1) ans = (1LL * ans + even) % MOD, odd++;
            else ans = (1LL * ans + odd) % MOD, even++;
        }
        return ans;
    }
};