class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        int atas = k - 1 + maxPts;
        vector<double> prob(atas + 1), pref(atas + 1);
        prob[0] =  pref[0] = 1;
        for (int i = 1; i <= atas; i++) {
            // double tmp = 0;
            // for (int j = min(k - 1, i - 1); j >= max(i - maxPts, 0); j--) {
            //     tmp += prob[j];
            // }
            int L = max(i - maxPts, 0), R = min(k - 1, i - 1);
            double tmp = (R >= 0) ? pref[R] : 0;
            if (L > 0 && L <= R) tmp -= pref[L - 1];
            tmp /= maxPts;
            prob[i] = tmp;
            pref[i] = pref[i - 1] + prob[i];
        }
        double lmao = 0;
        for (int i = k; i <= min(atas, n); i++) {
            lmao += prob[i];
        }
        return lmao;
    }
};