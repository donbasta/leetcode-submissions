class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 > num2) swap(num1, num2);
        int op = 0;
        while (num1 > 0) {
            num2 -= num1;
            op++;
            if (num1 > num2) swap(num1, num2);
        }
        return op;
    }
};