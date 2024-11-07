class Solution {
public:
    long long maximumTotalSum(vector<int>& mh) {
        using ll = long long;
        sort(mh.begin(), mh.end());
        reverse(mh.begin(), mh.end());
        ll ans = mh[0], last = mh[0], n = mh.size();
        
        for (int i = 1; i < n; i++) {
            if (last == 1) {
                return -1;
            }
            last = min(last - 1, 1ll * mh[i]);
            ans += last;
        }

        return ans;
    }
};