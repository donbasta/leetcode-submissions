class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) return false;
        int fi = sum / 3;
        int cur = 0;
        int i = 0;
        int cnt = 0;
        while (i < n) {
            cur += arr[i];
            if (cur == fi) {
                cnt++;
                cur = 0;
            }
            i++;
            if (cnt == 2) break;
        }
        return (cnt >= 2) && (i < n);
    }
};