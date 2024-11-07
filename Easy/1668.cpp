class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string tmp = word;
        int ret = 1;
        while (tmp.length() <= sequence.length()) {
            if (sequence.find(tmp) == string::npos) {
                break;
            }
            ret++;
            tmp += word;
        }
        return ret - 1;
    }
};