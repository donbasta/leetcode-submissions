class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i++) {
                for (int j = i; j < i + len; j++) {
                    sum += arr[j];
                }
            }
        }
        return sum;
    }
};