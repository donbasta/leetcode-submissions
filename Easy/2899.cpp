class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ret;
        vector<int> cur;
        int len = 0;
        for (auto c : words) {
            if (c == "prev") {
                len++;
                int sz = cur.size();
                if (sz < len) {
                    ret.push_back(-1);
                } else {
                    ret.push_back(cur[sz - len]);
                }
            } else {
                cur.push_back(stoi(c));
                len = 0;
            }
        }
        return ret;
    }
};