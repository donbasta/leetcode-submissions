class Solution {
public:
    string decodeString(string s) {
        int last = 0;
        vector<string> ve;
        string ret;
        ve.push_back(ret);
        vector<int> coef;
        coef.push_back(1);
        string buf_int;
        for (auto c : s) {
            if (c == '[') {
                string nw;
                last++;
                ve.push_back(nw);
                coef.push_back(stoi(buf_int));
                buf_int.clear();
            } else if (c == ']') {
                for (int i = 0; i < coef.back(); i++) {
                    ve[last - 1] += ve[last];
                }
                ve.pop_back();
                coef.pop_back();
                last--;
            } else if (c >= 'a' && c <= 'z') {
                ve[last].push_back(c);
            } else if (c >= '0' && c <= '9') {
                buf_int.push_back(c);
            }
        }
        assert (last == 0);
        return ve[last];
    }
};