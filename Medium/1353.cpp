class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int MX = 1e5;
        vector<vector<int>> start(MX + 1);
        for (auto e : events) {
            start[e[0]].push_back(e[1]);
        }
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> last_days;
        for (int i = 1; i <= MX; i++) {
            while (!last_days.empty() && last_days.top() < i) last_days.pop();
            for (auto ev : start[i]) {
                last_days.push(ev);
            }
            if (!last_days.empty()) {
                last_days.pop();
                ans++;
            }
        }
        return ans;
    }
};