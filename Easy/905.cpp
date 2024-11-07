class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> e, o;
        for (auto c : nums) {
            if (c & 1) o.push_back(c);
            else e.push_back(c);
        }
        for (auto c : o) e.push_back(c);
        return e;
    }
};