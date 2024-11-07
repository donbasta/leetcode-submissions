class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int cnt = count(s.begin(), s.end(), letter);
        return (cnt * 100) / n;
    }
};