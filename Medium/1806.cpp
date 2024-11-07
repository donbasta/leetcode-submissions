class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) return 1;
        int a = 2;
        int cnt = 1;
        while (true) {
            cnt++;
            a = (a * 2) % (n - 1);
            if (a == 1) break;
        }
        return cnt;
    }
};