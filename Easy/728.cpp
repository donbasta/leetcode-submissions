class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ve;
        for (int i = left; i <= right; i++) {
            int tmp = i;
            bool ok = true;
            while (tmp) {
                if ((tmp % 10 == 0) || (i % (tmp % 10) != 0)) {
                    ok = false;
                    break;
                }
                tmp /= 10;
            }
            if (ok) ve.push_back(i);
        }   
        return ve;
    }
};