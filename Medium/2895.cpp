class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        int n = processorTime.size();
        sort(tasks.begin(), tasks.end(), greater<>());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, processorTime[i] + tasks[4 * i]);
            ans = max(ans, processorTime[i] + tasks[4 * i + 1]);
            ans = max(ans, processorTime[i] + tasks[4 * i + 2]);
            ans = max(ans, processorTime[i] + tasks[4 * i + 3]);
        }
        return ans;
    }
};