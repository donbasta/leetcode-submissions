class Solution {
public:
    int nextGreaterElement(int n) {
        string sn = to_string(n);
        int len = sn.length();
        if (len == 1) return -1;
        int cur_max = sn.back() - '0';
        vector<char> rem;
        rem.push_back(sn.back());
        for (int i = len - 2; i >= 0; i--) {
            int cur = sn[i] - '0';
            rem.push_back(sn[i]);
            if (cur_max > cur) {
                string ret = sn;
                int take = -1;
                sort(rem.begin(), rem.end());
                for (int j = 0; j < (int)rem.size(); j++) {
                    if (rem[j] - '0' > cur) {
                        take = rem[j] - '0';
                        break;
                    }
                }
                assert(take != -1);
                ret[i] = (char)take + '0';
                bool ok = false;
                int cur_idx = i + 1;
                for (int j = 0; j < (int)rem.size(); j++) {
                    if ((!ok) && (rem[j] - '0' == take)) {
                        ok = true;
                        continue;
                    }
                    ret[cur_idx++] = rem[j];
                }
                long long cek = stoll(ret);
                // cout << cek << '\n';
                if (cek > 1ll * INT_MAX) return -1;
                return cek;
            }
            cur_max = max(cur_max, cur);
        }
        return -1;
    }
};