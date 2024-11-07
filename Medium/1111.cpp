class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ret;
        int a = 0, b = 0;
        for (auto c : seq) {
            int cur;
            if (c == '(') {
                if (a <= b) {
                    a++;
                    cur = 0;
                } else {
                    b++;
                    cur = 1;
                }
            } else {
                if (a >= b) {
                    a--;
                    cur = 0;
                } else {
                    b--;
                    cur = 1;
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};