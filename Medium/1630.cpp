class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int q = l.size();
        assert(q == r.size());
        vector<bool> hehe(q);
        for (int i = 0; i < q; i++) {
            vector<int> bruh(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(bruh.begin(), bruh.end());
            int dif = bruh[1] - bruh[0];
            bool cur = true;
            for (int j = 1; j < bruh.size(); j++) {
                if (bruh[j] - bruh[j - 1] != dif) {
                    cur = false;
                    break;
                }
            }
            hehe[i] = cur;
        }
        return hehe;
    }
};