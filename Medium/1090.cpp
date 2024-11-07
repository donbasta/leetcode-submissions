class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
            return values[a] > values[b];
        });
        int take = 0;
        int ans = 0;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (cnt[labels[idx[i]]] >= useLimit) continue;
            cnt[labels[idx[i]]]++;
            ans += values[idx[i]];
            take++;
            if (take >= numWanted) break;
        }
        return ans;
    }
};