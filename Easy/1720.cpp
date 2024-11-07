class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret;
        ret.push_back(first);
        for (auto c : encoded) {
            ret.push_back(c ^ ret.back());
        }
        return ret;
    }
};