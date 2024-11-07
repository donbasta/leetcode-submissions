class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        using ll = long long;
        ll mx = *max_element(milestones.begin(), milestones.end());
        ll tot = accumulate(milestones.begin(), milestones.end(), 0ll) - mx;
        return tot + min(mx, tot + 1);
    }
};