class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
        ll n1 = num1, n2 = num2;
        // num1 = (2^(a1) + ... + 2^(ar)) + r * num2, r minimal = ...
        // num1 - r * num2 harus punya maximal r bit on, and valuenya >= r, r minimal = ...
        ll r = 1;
        // if (n1 == 112577768 && n2 == -501662198) return 16;
        // if (n1 == 20567446 && n2 == -331049348) return 15;
        // if (n1 == 357832879 && n2 == -307093158) return 15;
        // if (n1 == 262112850 && n2 == -452277988) return 14;
        // if (n1 == 85315525 && n2 == -515752070) return 18;
        // if (n1 == 1000000000 && n2 == -1000000000) return 12;
        while (n1 - r * n2 >= r) {
            if (__builtin_popcountll(n1 - r * n2) <= r) {
                return r;
            }
            r++;
        }
        return -1;
    }
};