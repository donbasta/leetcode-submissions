class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ret;
        string tmp;
        for (int i = 0; i < target.length(); i++) {
            tmp.push_back('a');
            ret.push_back(tmp);
            while (tmp.back() != target[i]) {
                tmp.back()++;
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};