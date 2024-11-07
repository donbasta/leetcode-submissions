class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        priority_queue<int> lmao;
        lmao.push(values[0]);
        int ans = -INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, values[i] - i + lmao.top());
            lmao.push(values[i] + i);
        }
        return ans;
    }
};