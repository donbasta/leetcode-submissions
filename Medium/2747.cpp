class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        vector<pair<int, int>> Q;
        for (int i = 0; i < q; i++) {
            Q.emplace_back(queries[i], i);
        }
        vector<int> ans(q);
        sort(Q.begin(), Q.end());

        sort(logs.begin(), logs.end(), [&](const vector<int>& A, const vector<int>& B) -> bool {
            return A[1] < B[1];
        });
        map<int, int> cnt;
        int sz = logs.size();
        int l = 0, r = 0;
        for (int i = 0; i < q; i++) {
            while (r < sz && logs[r][1] <= Q[i].first) {
                cnt[logs[r][0]]++;
                r++;
            }
            while (l < sz && logs[l][1] < Q[i].first - x) {
                cnt[logs[l][0]]--;
                if (cnt[logs[l][0]] == 0) cnt.erase(logs[l][0]);
                l++;
            }
            ans[Q[i].second] = n - cnt.size();
        }
        return ans;
    }
};