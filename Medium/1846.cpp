class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int prv = 1;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] <= prv + 1) {
                prv = arr[i];
            } else {
                prv++;
            }
        }
        return prv;
    }
};