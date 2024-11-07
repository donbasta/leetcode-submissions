class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(), nums.end(), greater<int>());
        int mx = 0;
        int seed = -1;
        unordered_map<int, int> cnt;
        for (auto c : nums) {
            int residue_class = ((c % space) + space) % space;
            int cur = 1 + cnt[residue_class];
            if (cur >= mx) {
                mx = cur;
                seed = c;
            }
            cnt[residue_class]++;
        }
        return seed;
    }
};