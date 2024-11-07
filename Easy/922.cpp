class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> p[2];
        for (auto e : nums) p[e & 1].push_back(e);
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n / 2; i++) {
            ans[i * 2] = p[0][i];
            ans[i * 2 + 1] = p[1][i];
        }
        return ans;
    }
};