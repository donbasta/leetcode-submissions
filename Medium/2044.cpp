class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < (1 << n); i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) tmp = (tmp | nums[j]);
            }
            cnt[tmp]++;
        }
        int mx = -1;
        int occ = 0;
        for (auto e : cnt) {
            if (e.first > mx) {
                mx = e.first;
                occ = e.second;
            }
        }
        return occ;
    }
};