class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (auto c : nums) {
            if (c < 0) neg.push_back(c);
            else pos.push_back(c);
        }
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n / 2; i++) {
            ret.push_back(pos[i]);
            ret.push_back(neg[i]);
        }
        return ret;
    }
};