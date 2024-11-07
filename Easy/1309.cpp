class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        int ptr = 0;
        string ret;
        while (ptr < n) {
            if (ptr + 2 < n && s[ptr + 2] == '#') {
                ret.push_back((char)('a' + stoi(s.substr(ptr, 2)) - 1));
                ptr += 3;
            } else {
                ret.push_back((char)(s[ptr] - '1' + 'a'));
                ptr++;
            }   
        }
        return ret;
    }
};