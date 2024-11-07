class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> ve;
        int n = num.length();
        for (int i = 0; i < n; i++) {
            int dig = num[i] - '0';
            while (!ve.empty() && (ve.back() > dig) && ((ve.size() + n - 1 - i) >= (n - k))) {
                ve.pop_back();
            }
            ve.push_back(dig);
        }
        string ret;
        for (int i = 0; i < n - k; i++) {
            if (ret.length() == 0 && ve[i] == 0) continue;
            ret.push_back((char)(ve[i] + '0'));
        }
        if (ret.length() == 0) return "0";
        return ret;
    }
};