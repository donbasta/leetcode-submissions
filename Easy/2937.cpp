class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        int ptr = 0;
        while (ptr < n1 && ptr < n2 && ptr < n3 && s1[ptr] == s2[ptr] && s1[ptr] == s3[ptr]) ptr++;
        if (ptr == 0) return -1;
        return (n1 + n2 + n3 - 3 * ptr);
    }
};