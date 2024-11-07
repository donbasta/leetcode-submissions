class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int part = 1;
        for (int i = 1; i < n; i++) {
            if (target[i] != target[i - 1]) {
                part++;
            }
        }
        return part - (target[0] == '0');
    }
};