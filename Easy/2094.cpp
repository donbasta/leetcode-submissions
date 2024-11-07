class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ve;
        set<int> se;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j || digits[k] % 2 != 0) continue;
                    int bil = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (se.count(bil)) continue;
                    se.insert(bil);
                    ve.push_back(bil);
                }
            }
        }

        sort(ve.begin(), ve.end());
        return ve;
    }
};