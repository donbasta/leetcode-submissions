class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> ve1, ve2;
        int cur1 = 0, cur2 = 0;
        ve1.push_back(0), ve2.push_back(0);
        for (auto c : answerKey) {
            cur1 += c == 'T';
            cur2 += c == 'F';
            ve1.push_back(cur1), ve2.push_back(cur2);
        }
        int n = answerKey.length();
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int a1 = lower_bound(ve1.begin(), ve1.end(), ve1[i] - k) - ve1.begin();
            int a2 = lower_bound(ve2.begin(), ve2.end(), ve2[i] - k) - ve2.begin();
            ans = max(ans, i - a1);
            ans = max(ans, i - a2);
        }
        return ans;
    }
};