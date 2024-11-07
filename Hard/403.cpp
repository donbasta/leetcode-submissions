class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> ada;
        for (auto s : stones) ada[s] = true;
        unordered_map<int, unordered_map<int, bool>> DP;
        const function<bool(int, int)> dp = [&](int from, int steps) -> bool {
            if (from == stones.back()) return true;
            if (from > stones.back()) return false;
            if (ada.find(from + steps) == ada.end()) return false;
            if (DP[from].find(steps) != DP[from].end()) return DP[from][steps];
            int can = false;
            for (int i = steps - 1; i <= steps + 1; i++) {
                if (i <= 0) continue;
                can = can || dp(from + steps, i);
            }
            return DP[from][steps] = can;
        };
        return dp(0, 1);
    }
};