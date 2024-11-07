class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int c = 0;
        int ptr = 0;
        while (ptr < n && binary[ptr] == '1') ptr++;
        if (ptr == n) return binary;
        for (int i = ptr; i < n; i++) c += binary[i] == '1';
        string ret(n, '1');
        ret[n - 1 - c] = '0';
        return ret;
    }
};