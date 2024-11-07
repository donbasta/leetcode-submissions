class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        vector<int> kiri(nums.begin(), nums.begin() + m);
        vector<int> kanan(nums.begin() + m, nums.end());
        vector<map<int, bool>> cari(n - m + 1);
        vector<pair<int, int>> hehe;
        int tot = 0;
        for (int i = 0; i < n; i++) tot += nums[i];
        for (int i = 0; i < (1 << m); i++) {
            int cnt = __builtin_popcount(i);
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    tmp += kiri[j];
                }
            }
            hehe.emplace_back(cnt, tmp);
        }
        for (int i = 0; i < (1 << (n - m)); i++) {
            int cnt = __builtin_popcount(i);
            int tmp = 0;
            for (int j = 0; j < (n - m); j++) {
                if ((i >> j) & 1) {
                    tmp += kanan[j];
                }
            }
            cari[cnt][tmp] = true;
        }
        for (auto lol : hehe) {
            int curSz = lol.first, curSum = lol.second;
            // cout << curSz << ' ' << curSum << '\n';
            for (int i = 0; i <= n - m; i++) {
                if (curSz == 0 && i == 0) continue;
                if (curSz + i == n) continue;
                int addSz = i;
                if ((curSz + addSz) * tot % n != 0) continue;
                int need = ((curSz + addSz) * tot / n) - curSum;
                if (cari[i].find(need) != cari[i].end()) {
                    // cout << " LOH " << curSum << ' ' << i << ' ' << need << '\n';
                    return true; 
                }
            }
        }
        return false;
    }
};