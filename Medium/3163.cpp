class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        int ptr = 0;
        while (ptr < n) {
            char cur = word[ptr];
            int time = 1;
            int tmp = ptr + 1;
            while (tmp < n && word[tmp] == cur) {
                tmp++;
                time++;
                if (time == 9) break;
            }
            ptr = tmp;
            comp.push_back((char)(time + '0'));
            comp.push_back(cur);
        }
        return comp;
    }
};