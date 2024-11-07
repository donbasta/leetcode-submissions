class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, r = 1e5;
        int can = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long tmp = 0;
            for (auto e : arr) {
                tmp += min(e, mid);
            }
            if (tmp < (1ll * target)) {
                l = mid + 1;
            } else if (tmp >= (1ll * target)) {
                can = mid;
                r = mid - 1;
            }
        }
        if (can == -1) {
            return *max_element(arr.begin(), arr.end());
        }
        long long tmp = 0;
        long long sel1, sel2;
        for (auto e : arr) tmp += min(e, can);
        sel1 = tmp - target;
        tmp = 0;
        for (auto e : arr) tmp += min(e, can - 1);
        sel2 = target - tmp;
        if (sel2 <= sel1) return (can - 1);
        return can;
    }
};