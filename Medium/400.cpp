class Solution {
public:
    int findNthDigit(int n) {
        int tmp = 0;
        int lmao = 1;
        int dig = 1;
        while (true) {
            if (dig == 1) lmao *= 9;
            else lmao *= 10;
            if (1ll * tmp + 1ll * lmao * dig >= 1ll * n) {
                break;
            }
            tmp += lmao * dig;
            dig++;
        }
        int x = (n - tmp) / dig;
        int xxx = 1;
        for (int i = 1; i < dig; i++) xxx *= 10;
        // 1 -> 10 ^ (dig - 1)
        // ...
        // x -> 10 ^ (dig - 1) + (x - 1)
        if ((n - tmp) % dig == 0) return (xxx + x - 1) % 10;
        xxx += x;
        string ret = to_string(xxx);
        return ret[((n - tmp) % dig) - 1] - '0';
    }
};