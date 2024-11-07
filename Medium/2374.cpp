class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n);
        for (int i = 0; i < n; i++) {
            score[edges[i]] += i;
        }
        long long mx = 0;
        int ret = -1;
        for (int i = 0; i < n; i++) {
            if (score[i] > mx) {
                mx = score[i];
                ret = i;
            }
        }
        return ret;
    }
};