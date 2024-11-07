class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ret = 0;
        for (auto d : details) {
            ret += (stoi(d.substr(11, 2)) > 60);
        }
        return ret;
    }
};