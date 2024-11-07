class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int ptr = 0;
        while (ptr < n && s[ptr] == 'a') ptr++;
        if (ptr == n) {
            s.back() = 'z';
            return s;
        }
        int ptr2 = ptr;
        ptr2++;
        while (ptr2 < n && s[ptr2] > 'a') ptr2++;
        for (int i = ptr; i < ptr2; i++) {
            s[i]--;
        }
        return s;
    }
};