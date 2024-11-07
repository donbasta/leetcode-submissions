class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int residue[k];
        memset(residue, 0, sizeof(residue));
        residue[0] = 1;
        int tot = 0;
        for (auto e : nums) {
            tot = (tot + e) % k;
            if (tot < 0) tot += k;
            residue[tot]++;
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += residue[i] * (residue[i] - 1) / 2;
        }
        return ans;
    }
};