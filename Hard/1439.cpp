class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        set<vector<int>> se;
        priority_queue<pair<int, vector<int>>> pq;

        int tmp = 0;
        for (int i = 0; i < m; i++) tmp += mat[i][0];
        vector<int> ve(m);
        pq.push(make_pair(-tmp, ve));
        se.insert(ve);
        int cur = 0;
        while (cur < k) {
            cur++;
            auto now = pq.top();
            pq.pop();
            int sum_now = -now.first;
            if (cur == k) {
                return sum_now;
            }
            vector<int> buf = now.second;
            // cout << cur << " - " << sum_now << " : ";
            // for (auto e : buf) cout << e << ' ';
            // cout << '\n';
            for (int i = 0; i < m; i++) {
                if (buf[i] == n - 1) continue;
                vector<int> xxx = buf;
                xxx[i]++;
                if (se.count(xxx)) continue;
                se.insert(xxx);
                int nx_sum = (sum_now + mat[i][xxx[i]] - mat[i][buf[i]]);
                pq.emplace(-nx_sum, xxx);
            }
        }
        return -1;
    }
};