class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int cur = num[i] - '0';
            if (i & 1) tot += cur;
            else tot -= cur;
        }
        return tot == 0;
    }
};