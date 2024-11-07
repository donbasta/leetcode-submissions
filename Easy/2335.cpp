class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int sum = accumulate(amount.begin(), amount.end(), 0);
        int ans;
        if (2 * amount.back() <= sum) {
            ans = (sum + 1) / 2;
        } else {
            ans = amount.back();
        }
        return ans;
    }
};