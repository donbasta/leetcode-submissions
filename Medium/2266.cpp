class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.length();
        int A[n + 5], B[n + 5];
        const int MOD = 1e9 + 7;
        A[0] = 1;
        A[1] = 1;
        A[2] = 2;
        for (int i = 3; i <= n; i++) {
            A[i] = (1ll * A[i - 1] + A[i - 2] + A[i - 3]) % MOD;
        }
        B[0] = 1;
        B[1] = 1;
        B[2] = 2;
        B[3] = 4;
        for (int i = 4; i <= n; i++) {
            B[i] = (1ll * B[i - 1] + B[i - 2] + B[i - 3] + B[i - 4]) % MOD;
        }

        char cur = pressedKeys[0];
        int st = 0;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (pressedKeys[i] != cur) {
                int len = i - st;
                int mul = (cur == '7' || cur == '9') ? B[len] : A[len];
                ans = (1ll * ans * mul) % MOD;
                st = i;
                cur = pressedKeys[i];
            }
        }
        int len = n - st;
        int mul = (cur == '7' || cur == '9') ? B[len] : A[len];
        ans = (1ll * ans * mul) % MOD;
        return ans;
    }
};