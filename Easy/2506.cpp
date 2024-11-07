class Solution {
public:
    int similarPairs(vector<string>& words) {
        for (auto& w : words) {
            sort(w.begin(), w.end());
            w.resize(unique(w.begin(), w.end()) - w.begin());
        }
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += words[i] == words[j];
            }
        }
        return ans;
    }
};