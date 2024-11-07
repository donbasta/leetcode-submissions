class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int lmao = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if (lmao == n) return letters[0];
        return letters[lmao];
    }
};