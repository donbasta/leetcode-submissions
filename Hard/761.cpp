class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.length();
        vector<int> val;
        val.push_back(0);
        int cur = 0;
        for (auto c : s) {
            if (c == '1') cur++;
            else cur--;
            val.push_back(cur);
        }

        function<void(int, int, int)> process = [&](int i, int j, int mn) {
            vector<int> piv;
            for (int x = i; x <= j; x++) {
                if (val[x] == mn) {
                    piv.push_back(x);
                }
            }
            int sz = piv.size();
            if (sz == 1) {
                return;
            }
            vector<string> tmp; 
            for (int ii = 1; ii < sz; ii++) {
                process(piv[ii - 1] + 1, piv[ii] - 1, mn + 1);
                tmp.push_back(s.substr(piv[ii - 1], piv[ii] - piv[ii - 1]));
            }
            sort(tmp.begin(), tmp.end(), greater<>());
            string nw = s.substr(0, piv[0]);
            for (auto t : tmp) {
                nw += t;
            }
            nw += s.substr(piv.back(), n - piv.back());
            s = nw;
        };

        process(0, n, 0);
        return s;
    }
};