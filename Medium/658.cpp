class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int R = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int L = R - 1;
        while (R - L - 1 < k) {
            if (L < 0) R++;
            else if (R >= arr.size()) L--;
            else {
                int a = x - arr[L], b = arr[R] - x;
                if (a <= b) {
                    L--;
                } else {
                    R++;
                }
            }
        }
        return vector<int>(arr.begin() + L + 1, arr.begin() + R);
    }
};