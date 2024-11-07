class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.length();
        int idx = 0;
        while (idx < n && (num[idx] - '0') >= change[num[idx] - '0']) idx++;
        for (int i = idx; i < n; i++) {
            if (num[i] - '0' > change[num[i] - '0']) break;
            if (num[i] - '0' == change[num[i] - '0']) continue;
            num[i] = change[num[i] - '0'] + '0';
        }
        return num;
    }
};