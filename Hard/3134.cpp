#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using ll = long long;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();

        ll cnt = 1ll * n * (n + 1) / 2;
        ll urutan_median = (cnt + 1) / 2;

        // calculate the number of subarrays whose distinct is <= T
        auto calc = [&](int T) -> ll {
            if (T == n) {
                return cnt;  
            }
            assert (T < n);
            
            ll ret = 0;
            ll ptr = -1;
            unordered_map<int, int> tmp;
            for (int i = 0; i < n; i++) {
                while (ptr + 1 < n && tmp.size() <= T) {
                    ptr++;
                    tmp[nums[ptr]]++;
                }
                if (tmp.size() > T) {
                    ret += ptr - i;   
                } else {
                    ret += n - i;
                }
                tmp[nums[i]]--;
                if (tmp[nums[i]] == 0) {
                    tmp.erase(nums[i]);
                }
            }
            return ret;
        };

        int l = 1, r = n, piv = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll y = calc(mid);
            if (y < urutan_median) {
                l = mid + 1;
            } else {    
                piv = mid;
                r = mid - 1;
            }
        }
        return piv;
    }
};