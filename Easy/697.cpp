class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int mx = 0;
        map<int, int> cnt, fi, la;
        int itr = 0;
        for (auto e : nums) {
            cnt[e]++;
            mx = max(mx, cnt[e]);
            la[e] = itr;
            if (!fi.count(e)) fi[e] = itr;
            itr++;
        }
        int ans = INT_MAX;
        for (auto e : cnt) {
            if (e.second != mx) continue;
            ans = min(ans, la[e.first] - fi[e.first] + 1);
        }
        return ans;
    }
};