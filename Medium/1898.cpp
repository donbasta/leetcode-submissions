class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int k = removable.size();
        int lo = 0, hi = k;
        int ans = 0;
        int np = p.length();
        int ns = s.length();
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            string cpp = s;
            for (int i = 0; i < mid; i++) {
                cpp[removable[i]] = '#';
            }
            bool ok = true;
            int ps = 0, pp = 0;
            for (; (ps < ns) && (pp < np); ps++, pp++) {
                while (ps < ns && cpp[ps] != p[pp]) ps++;
                if (ps == ns) ok = false;
            }
            if (pp < np) ok = false;
            if (ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};