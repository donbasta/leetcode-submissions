class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int n = b.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                ret++;
                for (int j = i + 1; j < n; j++) {
                    b[j] = max(0, b[j] - 1);
                }
            }
        }
        return ret;
    }
};