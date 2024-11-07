class Solution {
public:
    int findIntegers(int n) {
        const int N = 30;
        int f[N + 5];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i <= N; i++) {
            f[i] = (f[i - 2] + f[i - 1]);
        }
        vector<int> dig_n;
        while (n) {
            dig_n.push_back(n & 1);
            n >>= 1;
        }
        reverse(dig_n.begin(), dig_n.end());

        int len = dig_n.size();
        int ans = 0;

        bool n_good = true;
        for (int i = 0; i < len; i++) {
            if (dig_n[i] == 1) {
                ans += f[len - i - 1];
                if (i > 0 && dig_n[i - 1] == 1) {
                    n_good = false;
                    break;
                }
            }
        }
        ans += n_good;
        return ans;
    }
};