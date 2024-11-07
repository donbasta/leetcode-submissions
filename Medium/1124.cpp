class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for (auto& e : hours) {
            if (e > 8) e = 1;
            else e = -1;
        }
        int n = hours.size();
        int sum = 0;
        int pre[n + 1];
        pre[0] = 0;
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            sum += hours[i - 1];
            int l = 0, r = i - 1;
            int ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid] <= sum - 1) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (ans != -1) {
                ret = max(ret, i - ans);
            }
            pre[i] = min(pre[i - 1], sum);
        }
        return ret;
    }
};