class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ve(1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> tmp(1, 1);
            for (int j = 0; j < ve.size() - 1; j++) {
                tmp.push_back(ve[j] + ve[j + 1]);
            }
            tmp.push_back(1);
            ve = tmp;
        }
        return ve;
    }
};