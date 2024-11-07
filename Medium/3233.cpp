class Solution {
public:
    int nonSpecialCount(int l, int r) {
        vector<int> pr;
        
        const int N = 1e5;
        vector<bool> is_pr(N, true);

        for (int i = 2; i <= N; i++) {
            if (!is_pr[i]) continue;
            pr.push_back(i);
            for (int j = i + i; j <= N; j += i) {
                is_pr[j] = false;
            }
        }

        int rem = 0;
        for (auto p : pr) {
            if (p * p > r) break;
            if (p * p < l) continue;
            rem++;
        }
        return (r - l + 1 - rem);
    }
};