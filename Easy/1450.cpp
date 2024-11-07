class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int sz = startTime.size();
        vector<int> ve(1002);
        for (int i = 0; i < sz; i++) {
            ve[startTime[i]]++;
            ve[endTime[i] + 1]--;
        }
        for (int i = 1; i <= 1000; i++) {
            ve[i] += ve[i - 1];
        }
        return ve[queryTime];
    }
};