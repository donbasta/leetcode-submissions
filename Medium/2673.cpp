class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int inc = 0;
        const function<int(int)> solve = [&](int v) -> int {
            if (v >= n) return 0;
            int x = solve(2 * v + 1);
            int y = solve(2 * v + 2);
            inc += abs(x - y);
            return cost[v] + max(x, y);
        };
        solve(0);
        return inc;
    }
};