// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();
        int c = rand7();
        int d = rand7();
        --a, --b, --c, --d;
        int lol = a * 343 + b * 49 + c * 7 + d;
        return (lol % 10) + 1;
    }
};