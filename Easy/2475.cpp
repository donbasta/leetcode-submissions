class Solution {
public:
    int unequalTriplets(vector<int>& arr) {
        int n = arr.size();
        int ok = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
            ok += abs(arr[i] - arr[j]) >= 1 && abs(arr[j] - arr[k]) >= 1 && abs(arr[i] - arr[k]) >= 1;
        }
        return ok;
    }
};