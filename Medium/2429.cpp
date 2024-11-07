class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        while (num2) {
            cnt += (num2 & 1);
            num2 >>= 1;
        }
        int B = 30;
        int ans = 0;
        for (int i = B; i >= 0; i--) {
            int set = (num1 >> i) & 1;
            if (set) {
                if (cnt > 0) cnt--;
                else ans += (1 << i);
            } else {
                if (cnt == (i + 1)) ans += (1 << i), cnt--; 
            }
        }
        assert(cnt == 0);
        return (ans ^ num1);
    }
};