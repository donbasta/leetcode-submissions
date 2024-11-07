class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_pr(right + 1, true);
        vector<int> pr;
        for (int i = 2; i <= right; i++) {
            if (!is_pr[i]) continue;
            if (i >= left) pr.push_back(i);
            for (int j = i + i; j <= right; j += i) is_pr[j] = false;
        }
        // for (auto p : pr) { cout << p << ' '; }
        vector<int> ret = {-1, -1};
        if (pr.size() <= 1) return ret;
        int gap = INT_MAX;
        for (int i = 1; i < pr.size(); i++) {
            if (pr[i] - pr[i - 1] < gap) {
                gap = pr[i] - pr[i - 1];
                ret = vector<int>{pr[i - 1], pr[i]};
            }
        }
        return ret;
    }
};