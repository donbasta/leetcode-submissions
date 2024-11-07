class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string tmp;
        string lol = "ab";
        if (y >= x) {
            swap(x, y);
            swap(lol[0], lol[1]);
        }
        int ret = 0;
        for (auto c : s) {
            if (!tmp.empty() && (tmp.back() == lol[0]) && (c == lol[1])) {
                ret += x;
                tmp.pop_back();
            } else {
                tmp.push_back(c);
            }
        }
        swap(lol[0], lol[1]);
        s = tmp;
        tmp.clear();
        for (auto c : s) {
            if (!tmp.empty() && tmp.back() == lol[0] && c == lol[1]) {
                ret += y;
                tmp.pop_back();
            } else {
                tmp.push_back(c);
            }
        }
        return ret;
    }
};