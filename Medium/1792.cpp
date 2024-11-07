class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        priority_queue<pair<double, pair<int, int>>> pq;
        double ans = 0;
        int n = classes.size();
        for (auto c : classes) {
            int p = c[0], t = c[1];
            double dp = p, dt = t;
            ans += dp / dt;
            pq.emplace((dp + 1) / (dt + 1) - dp / dt, make_pair(p, t));
        }
        for (int i = 1; i <= ex; i++) {
            auto take = pq.top();
            pq.pop();
            ans += take.first;
            int p = take.second.first, t = take.second.second; 
            double dp = p, dt = t;
            pq.emplace((dp + 2) / (dt + 2) - (dp + 1) / (dt + 1), make_pair(p + 1, t + 1));
        }
        return ans / (double)n;
    }
};