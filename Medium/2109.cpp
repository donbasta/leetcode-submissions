class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret;
        int len = s.length();
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (j < spaces.size() && i == spaces[j]) {
                j++;
                ret.push_back(' ');
            }
            ret.push_back(s[i]);
        }
        return ret;
    }
};