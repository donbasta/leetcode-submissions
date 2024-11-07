class Solution {
public:
    double average(vector<int>& salary) {
        int mn = *min_element(salary.begin(), salary.end());
        int mx = *max_element(salary.begin(), salary.end());
        int tot = accumulate(salary.begin(), salary.end(), 0);
        tot -= (mn + mx);
        double ans = (double)tot / (salary.size() - 2);
        return ans;
    }
};