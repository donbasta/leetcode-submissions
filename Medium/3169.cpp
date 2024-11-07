class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int la = 0;
        int ans = 0;
        for (auto m : meetings) {
            if (m[0] > la) {
                ans += max(0, min(m[0] - 1, days) - la);
            }
            la = max(la, m[1]);
        }
        ans += max(0, days - la);
        return ans;
    }
};