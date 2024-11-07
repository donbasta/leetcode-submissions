class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int len = 1;
        int cur = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) len++;
            else {
                if (len * 4 > n) return cur;
                len = 1;
                cur = arr[i];
            }
        }
        if (len * 4 > n) {
            return cur;
        }
        assert(false);
        return -1;
    }
};