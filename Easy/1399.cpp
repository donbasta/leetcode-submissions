class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int sm = 0;
            int ci = i;
            while (ci) {
                sm += ci % 10;
                ci /= 10;
            }
            mp[sm]++;
        }
        int mx = -1;
        for (auto e : mp) {
            mx = max(mx, e.second);
        }
        int ans = 0;
        for (auto e : mp) {
            ans += e.second == mx;
        }
        return ans;
    }
};