class Solution {
public:
    int minimumSum(int num) {
        string st = to_string(num);
        sort(st.begin(), st.end());
        return 10 * ((st[0] - '0') + (st[1] - '0')) + ((st[2] - '0') + (st[3] - '0'));
    }
};