class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> ret;

        function<void(int, vector<int>)> rec = [&](int sz, vector<int> S) {
            if (sz == 0) return;
            sort(S.begin(), S.end());
            int val = S.back() - S[S.size() - 2];
            if (S.back() == 0) val = -val;
            ret.push_back(val);

            if (val < 0) reverse(S.begin(), S.end());
            vector<int> tmp1, tmp2;
            unordered_map<int, int> pend;
            bool ok = false;
            for (int i = 0; i < (1 << sz); i++) {
                if (pend[S[i] - val]) {
                    tmp1.push_back(S[i] - val);
                    tmp2.push_back(S[i]);
                    if (S[i] - val == 0) ok = true;
                    pend[S[i] - val]--;
                } else {
                    pend[S[i]]++;
                }
            }
            if (ok) rec(sz - 1, tmp1);
            else {
                ret.back() *= -1;
                rec(sz - 1, tmp2);
            }
        };

        rec(n, sums);
        return ret;
    }
};