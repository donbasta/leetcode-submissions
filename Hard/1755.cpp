class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        if (n == 1) return min(abs(goal), abs(nums[0] - goal));
        int a_size = (n / 2), b_size = n - (n / 2);
        int a[a_size], b[b_size];
        for (int i = 0; i < (n / 2); i++) a[i] = nums[i];
        for (int i = (n / 2); i < n; i++) b[i - (n / 2)] = nums[i];
        int sz_a = (1 << a_size);
        int sz_b = (1 << b_size);
        int sa[sz_a], sb[sz_b];
        for (int i = 0; i < sz_a; i++) {
            int tmp = 0;
            for (int j = 0; j < a_size; j++) {
                if (i & (1 << j)) tmp += a[j];
            }
            sa[i] = tmp;
        }
        for (int i = 0; i < sz_b; i++) {
            int tmp = 0;
            for (int j = 0; j < b_size; j++) {
                if (i & (1 << j)) tmp += b[j];
            }
            sb[i] = tmp;
        }
        sort(sa, sa + sz_a);
        sort(sb, sb + sz_b);
        int ia = 0, ib = sz_b - 1;
        int ret = INT_MAX;

        while (ia < sz_a) {
            while ((ib >= 0) && (sa[ia] + sb[ib] > goal)) ib--;
            if (ib >= 0) ret = min(ret, goal - (sa[ia] + sb[ib]));
            if (ib < (sz_b - 1)) ret = min(ret, sa[ia] + sb[ib + 1] - goal);
            ia++;
        }
        return ret;
    }
};