class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans = 0;
        pair<int, int> tmp[n];
        for (int i = 0; i < n; i++) {
            tmp[i] = make_pair(efficiency[i], speed[i]);
        }
        sort(tmp, tmp + n, [&](pair<int, int> a, pair<int, int> b) -> bool {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, 1ll * tmp[i].first * (sum + tmp[i].second));
            if (!pq.empty() && pq.size() == k - 1 && pq.top() < tmp[i].second) {
                sum += (tmp[i].second - pq.top());
                pq.pop();
                pq.push(tmp[i].second);
            } else if (pq.size() < k - 1) {
                sum += tmp[i].second;
                pq.push(tmp[i].second);
            }
        }
        const int MOD = 1e9 + 7;
        ans %= MOD;
        return ans;
    }
};