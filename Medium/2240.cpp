class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        using ll = long long;
        // x * cost1 + y * cost2 <= total
        ll ans = 0;
        for (int x = 0; x * cost1 <= total; x++) {
            int rem = total - x * cost1;
            ans += (1 + (rem / cost2));
        }
        return ans;
    }
};