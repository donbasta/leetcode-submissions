class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref, suf;
        pref.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                pref.push_back(arr[i]);
            } else {
                break;
            }
        }
        if (pref.size() == n) return 0;
        suf.push_back(arr.back());
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                suf.push_back(arr[i]);
            } else {
                break;
            }
        }
        reverse(suf.begin(), suf.end());
        int mx = (int)suf.size();
        for (int i = 0; i < (int)pref.size(); i++) {
            int x = lower_bound(suf.begin(), suf.end(), pref[i]) - suf.begin();
            mx = max(mx, i + 1 + (int)suf.size() - x);
        }
        return n - mx;
    }
};