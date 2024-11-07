class Solution {
public:
    bool good(int x) {
        // check whether x * x can be partitioned into several integers such that the sum is x
        string s = to_string(x * x);
        int ns = s.length();
        vector<vector<int>> DP(ns, vector<int>(x + 1, -1));
        const function<int(int, int)> dp = [&](int idx, int sum) -> int {
            if (idx == ns) return sum == 0;
            if (DP[idx][sum] != -1) return DP[idx][sum];
            int i = idx;
            while (i < ns) {
                int a = stoi(s.substr(idx, i - idx + 1));
                if (a > sum) break;
                if (dp(i + 1, sum - a)) {
                    return DP[idx][sum] = 1;
                }
                i++;
            }
            return DP[idx][sum] = 0;
        };
        return dp(0, x);
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i += 9) {
            if (good(i)) ans += i * i;
        }
        for (int i = 9; i <= n; i += 9) {
            if (good(i)) ans += i * i;
        }
        return ans;
    }
};