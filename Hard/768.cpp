class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int, int>> ve;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            ve.emplace_back(arr[i], i);
        }
        sort(ve.begin(), ve.end());
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[ve[i].second] = i;
        }
        int mx = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, pos[i]);
            if (mx == i) {
                ans++;
            }
        }
        return ans;
    }
};