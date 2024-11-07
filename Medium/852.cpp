class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1, r = n - 2;
        int ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[mid] > arr[mid - 1]) {
                ans = mid;
                l = mid + 1;
            } else if (arr[mid] < arr[mid - 1]) {
                r = mid - 1;
            }
        }
        return ans;
    }
};