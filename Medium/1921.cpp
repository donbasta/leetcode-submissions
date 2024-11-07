class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        int tm[n];
        for (int i = 0; i < n; i++) {
            tm[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(tm, tm + n);
        for (int i = 0; i < n; i++) {
            if (tm[i] <= i) return i;
        }
        return n;
    }
};