class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> pre(limit + limit + 5);
        const function<void(int, int)> addRange = [&](int l, int r) -> void {
            if (l > r) return;
            pre[l]++;
            pre[r + 1]--;
        };
        int n = nums.size();
        for (int i = 0; i < (n / 2); i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            if (a > b) swap(a, b);
            addRange(2, a + b - 1);
            addRange(a + b + 1, limit + limit);
            addRange(2, a);
            addRange(b + limit + 1, limit + limit);
        }
        for (int i = 1; i <= limit + limit; i++) {
            pre[i] += pre[i - 1];
        }
        int mn = INT_MAX;
        for (int i = 2; i <= limit + limit; i++) {
            mn = min(mn, pre[i]);
        }
        return mn;
    }
};