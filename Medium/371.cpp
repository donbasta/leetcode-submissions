class Solution {
public:
    int getSum(int a, int b) {
        for (int i = 1; i <= abs(b); i++) {
            if (b > 0) a++;
            else a--;
        } 
        return a;
    }
};