class Solution {
public:
    long long maxScore(vector<int>& nums) {
        using ll = long long;
        auto lcm = [&](ll x, ll y) -> ll {
            return x * (y / __gcd(x, y));  
        };
        int n = nums.size();
        ll a1 = nums[0], a2 = nums[0];
        for (int i = 1; i < n; i++) {
            a1 = lcm(a1, 1ll * nums[i]), a2 = __gcd(a2, 1ll * nums[i]);
        }
        ll ans = a1 * a2;
        
        for (int i = 0; i < n; i++) {
            vector<ll> tmp;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                tmp.push_back(nums[j]);
            }
            if (tmp.empty()) continue;
            ll x1 = tmp[0], x2 = tmp[0];
            for (int j = 1; j < n - 1; j++) {
                x1 = lcm(x1, tmp[j]);
                x2 = __gcd(x2, tmp[j]);
            }
            ans = max(ans, x1 * x2);
        }
        return ans;
    }
};