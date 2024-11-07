class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> used(n);
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (used[j]) continue;
                string tmp = words[j];
                reverse(tmp.begin(), tmp.end());
                if (tmp == words[i]) {
                    used[i] = used[j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};