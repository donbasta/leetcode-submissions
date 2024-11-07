class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto e : nums) {
            vector<int> tmp;
            while (e) {
                tmp.push_back(e % 10);
                e /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            for (auto t : tmp) ans.push_back(t);
        }
        return ans;
    }
};