class Solution {
public:
    int twoEggDrop(int n) {
        int cur = 0;
        while (n > 0) {
            cur++;
            n -= cur;
        }
        return cur;
    }
};