class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> se;
        for (auto w : bannedWords) se.insert(w);
        int check = 0;
        for (auto m : message) check += se.count(m);
        return check >= 2;
    }
};