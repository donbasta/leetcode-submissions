class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end());
        int n = inventory.size();
        using ll = long long;
        ll ans = 0;

        const ll MOD = 1e9 + 7;
        auto F = [&](int a, int b) -> ll { //a + (a + 1) + ... + b
            if (a > b) return 0;
            ll ret = 1ll * (a + b) * (b - a + 1) / 2;
            return ret % MOD;
        };
        
        for (int i = n - 1; i >= 0; i--) {
            int prv = (i ? inventory[i - 1] : 0);
            if (inventory[i] == prv) continue;
            ll avail = 1ll * (n - i) * (inventory[i] - prv);
            if (avail <= 1ll * orders) {
                orders -= avail;
                ll add = 1ll * (n - i) * F(prv + 1, inventory[i]) % MOD;
                ans = (ans + add) % MOD;
            } else {
                ll Q = orders / (n - i);
                ll R = orders % (n - i);
                // cout << Q << ' ' << R << '\n';
                ll add = 1ll * (n - i) * F(inventory[i] - Q + 1, inventory[i]) % MOD;
                ans = (ans + add) % MOD;
                ans = (ans + 1ll * (inventory[i] - Q) * R) % MOD;
                break;
            }
            // cout << ans << '\n';
        }
        return ans;
    }
};