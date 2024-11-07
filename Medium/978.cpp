class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> tmp;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) tmp.push_back(0);
            else {
                if (i & 1) {
                    if (arr[i] > arr[i - 1]) tmp.push_back(1);
                    else tmp.push_back(-1);
                } else {
                    if (arr[i] < arr[i - 1]) tmp.push_back(1);
                    else tmp.push_back(-1);
                }
            }
        }
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n - 1; i++) {
            if (tmp[i] == 0) {
                ans = max(ans, cur);
                cur = 0;
            } else if (i == 0 || tmp[i] == tmp[i - 1]) {
                cur++;
            } else {
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);
        return ans + 1;
    }
};