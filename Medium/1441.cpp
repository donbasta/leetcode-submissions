class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1;
        vector<int> ve;
        int idx = 0;
        vector<string> ret;
        while (cur <= n) {
            if (target[idx] == cur) {
                if (idx == 0) {
                    while (!ve.empty()) {
                        ret.push_back("Pop");
                        ve.pop_back();
                    }
                } else {
                    while (!ve.empty() && ve.back() != target[idx - 1]) {
                        ret.push_back("Pop");
                        ve.pop_back();
                    }
                }
                idx++;
            }
            ret.push_back("Push");
            ve.push_back(cur);
            if (cur == target.back()) {
                break;
            }
            cur++;
        }
        return ret;
    }
};