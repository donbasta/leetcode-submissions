class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fc(n + 1);
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = fc[i - 1] * i;
        }
        --k;
        string res;
        vector<bool> taken(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int d = k / fc[i];
            k %= fc[i];
            char nx;
            for (int j = 1; j <= n; j++) {
                if (taken[j]) continue;
                --d;
                if (d < 0) {
                    taken[j] = true;
                    nx = (char)(j + '0');
                    break;
                }
            }
            res.push_back(nx);
        }
        return res;
    }
};