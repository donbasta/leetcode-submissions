class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long check = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i != 0) continue;
            check += i;
            if (i * i != num) check += num / i;
        }
        return (check == 2ll * num);
    }
};