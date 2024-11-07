class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ks = 0;
        for (auto d : derived) ks ^= d;
        return ks == 0;
    }
};