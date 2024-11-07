class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> ve;
        int n = quality.size();
        for (int i = 0; i < n; i++) {
            double a = (double) wage[i] / (double) quality[i];
            ve.emplace_back(a, quality[i]);
        }
        sort(ve.begin(), ve.end());
        int sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k - 1; i++) {
            sum += ve[i].second;
            pq.push(ve[i].second);
        }

        double ans = 1e18;
        for (int i = k - 1; i < n; i++) {
            ans = min(ans, ve[i].first * (sum + ve[i].second));
            if (!pq.empty() && (pq.top() > ve[i].second)) {
                sum -= (pq.top() - ve[i].second);
                pq.pop();
                pq.push(ve[i].second);
            }
        }
        return ans;
    }
};