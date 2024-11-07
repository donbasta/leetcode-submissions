class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= limit; i++) {
            int sisa = n - i;
            if (sisa < 0) continue;
            if (sisa > 2 * limit) continue;
            int le = max(0, sisa - limit);
            int ri = min(limit, sisa);
            ans += (ri - le + 1);
        }
        return ans;
    }
};