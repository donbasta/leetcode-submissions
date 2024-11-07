class Solution {
public:
    int n;
    vector<int> b;
    Solution(int n, vector<int>& blacklist) : n(n) {
        b = blacklist;
        sort(b.begin(), b.end());
    }
    
    int pick() {
        int sz = b.size();
        int a = rand() % (n - sz);
        int l = 0, r = n - 1;
        int t;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cek = mid - (lower_bound(b.begin(), b.end(), mid) - b.begin());
            if (cek > a) {
                r = mid - 1;
            } else {
                t = mid;
                l = mid + 1;
            }
        }
        return t;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */