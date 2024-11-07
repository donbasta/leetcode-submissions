class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int tmp = 0;
        for (int i = 0; i < k - 1; i++) {
            tmp += arr[i];
        }
        int ans = 0;
        for (int i = k - 1; i < arr.size(); i++) {
            tmp += arr[i];
            if (tmp >= threshold * k) ans++;
            tmp -= arr[i - k + 1];
        }
        return ans;
    }
};