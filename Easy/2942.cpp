class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            bool ada = false;
            for (auto c : words[i]) {
                if (c == x) ada = true;
            }
            if (ada) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};