class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, arr[i]);
            if (mx == i) ans++;
        }
        return ans;
    }
};