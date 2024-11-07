class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> last;
        int n = tasks.size();
        long long cur = 1;
        for (int i = 0; i < n; i++) {
            if (last.find(tasks[i]) != last.end() && last[tasks[i]] > cur - (space + 1)) {
                cur = last[tasks[i]] + space + 1;
            }
            last[tasks[i]] = cur;
            cur++;
        }
        return (cur - 1);
    }
};