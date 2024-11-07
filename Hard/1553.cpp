class Solution {
public:
    unordered_map<int, int> ump;
    int minDays(int n) {
        if (n == 1) return 1;
        if (ump.count(n)) return ump[n];
        int ret = 1 + minDays(n / 2) + (n % 2);
        if (n >= 3) ret = min(ret, 1 + minDays(n / 3) + (n % 3));
        return ump[n] = ret;
    }
};