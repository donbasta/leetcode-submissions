class Solution {
public:
    int minTimeToType(string word) {
        int cur = 0;
        int ans = 0;
        for (auto c : word) {
            int now = c - 'a';
            int dis = abs(now - cur);
            ans += min(dis, 26 - dis);
            ans++;
            cur = now;
        }
        return ans;
    }
};