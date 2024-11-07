class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        if (x > y) swap(x, y);
        vector<int> ans(n);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int dis = j - i;
                dis = min(dis, abs(i - x) + 1 + abs(j - y));
                dis = min(dis, abs(i - y) + 1 + abs(j - x));
                ans[dis - 1]++;
            }
        }
        for (int i = 0; i < n; i++) ans[i] *= 2;
        return ans;
    }
};