class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int mx = *max_element(arr.begin(), arr.end());
        if (k >= n - 1) {
            return mx;
        }
        int cur = max(arr[0], arr[1]);
        int str = 1;
        if (k == 1) return cur;
        for (int i = 2; i < n; i++) {
            if (cur > arr[i]) str++;
            else {
                str = 1;
                cur = arr[i];
            }
            if (str == k) return cur;
        }
        return mx;
    }
};