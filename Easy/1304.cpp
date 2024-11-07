class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ve;
        if (n & 1) ve.push_back(0);
        for (int i = 0; i < n / 2; i++) {
            ve.push_back(i + 1);
            ve.push_back(-(i + 1));
        }
        return ve;
    }
};