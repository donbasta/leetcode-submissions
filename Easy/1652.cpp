class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                int tmp = (i + 1) % n;
                for (int j = 0; j < k; j++) {
                    ret[i] += code[tmp];
                    tmp = (tmp + 1) % n;
                }
            } else if (k < 0) {
                int tmp = (i + n - 1) % n;
                for (int j = 0; j < abs(k); j++) {
                    ret[i] += code[tmp];
                    tmp = (tmp + n - 1) % n;
                }
            }
        }
        return ret;
    }
};