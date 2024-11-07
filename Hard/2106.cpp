class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int ans = 0;
        int f1 = -1, f2 = -1;

        int pre[n];
        for (int i = 0; i < n; i++) {
            pre[i] = fruits[i][1] + (i ? pre[i - 1] : 0);
        }
        auto get = [&](int l, int r) -> int {
            if (l > r) return 0;
            return pre[r] - (l ? pre[l - 1] : 0);
        };

        for (int i = 0; i < n; i++) {
            if (fruits[i][0] < startPos) continue;
            if (f1 == -1) f1 = i;
            int ri = fruits[i][0] - startPos;
            if (ri > k) break;
            int take = get(f1, i);
            int le = k - ri;
            int ptr = lower_bound(fruits.begin(), fruits.end(), vector<int>{fruits[i][0] - le, 0}) - fruits.begin();
            take += get(ptr, f1 - 1);
            ans = max(ans, take);
        }

        const int INF = 2e9;
        for (int i = n - 1; i >= 0; i--) {
            if (fruits[i][0] > startPos) continue;
            if (f2 == -1) f2 = i;
            int le = startPos - fruits[i][0];
            if (le > k) break;
            int take = get(i, f2);
            int ri = k - le;
            int ptr = upper_bound(fruits.begin(), fruits.end(), vector<int>{fruits[i][0] +  ri, INF}) - fruits.begin() - 1;
            take += get(f2 + 1, ptr);
            ans = max(ans, take);
        }

        return ans;
    }
};