class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp;
        for (auto e : arr) {
            if (e == 0) tmp.push_back(0);
            tmp.push_back(e);
        }
        tmp.resize(arr.size());
        arr = tmp;
    }
};