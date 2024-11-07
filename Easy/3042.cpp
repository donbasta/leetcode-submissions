class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].size() > words[j].size()) continue;
                bool p = true, s = true;
                for (int k = 0; k < (int)words[i].size(); k++) {
                    if (words[i][k] != words[j][k]) {
                        p = false;
                        break;
                    }
                }
                for (int k = 0; k < (int)words[i].size(); k++) {
                    if (words[i][words[i].size() - 1 - k] != words[j][words[j].size() - 1 - k]) {
                        s = false;
                        break;
                    }
                }
                ans += (p && s);
            }
        }
        return ans;
    }
};