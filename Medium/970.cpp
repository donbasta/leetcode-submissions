class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ve;
        if (x == 1 && y == 1) {
            if (bound >= 2) ve.push_back(2);
            return ve;
        }
        if (x > y) swap(x, y);
        if (x == 1) {
            int pw = 1;
            while (pw + 1 <= bound) {
                ve.push_back(pw + 1);
                pw *= y;
            }
            return ve;
        }

        int pw = 1;
        while (true) {
            if (pw > bound) break;
            int pw2 = 1;
            while (pw + pw2 <= bound) {
                ve.push_back(pw + pw2);
                pw2 *= y;
            }
            pw *= x;
        }

        sort(ve.begin(), ve.end());
        ve.resize(unique(ve.begin(), ve.end()) - ve.begin());

        return ve;
    }
};