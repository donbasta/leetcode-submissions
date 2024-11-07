class Solution {
public:
    int mod = 1e9 + 7;
    int fpow(int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1ll * ret * a) % mod;
            a = (1ll * a * a) % mod;
            b >>= 1;
        }
        return ret;
    }
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 4) return primeFactors; 
        int x = primeFactors % 3;
        int y = primeFactors / 3;
        if (x == 0) return fpow(3, y);
        else if (x == 1) return (4ll * fpow(3, y - 1)) % mod; 
        else return (2ll * fpow(3, y)) % mod;
    }
};