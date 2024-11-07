class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sumEven = 0;
        for (auto n : nums) {
            if (n % 2 == 0) sumEven += n;
        }
        // cout << sumEven << '\n';
        for (auto q : queries) {
            int val = q[0], index = q[1];
            int old = nums[index], nw = nums[index] + val;
            // cout << old << ' ' << nw << '\n';
            int aold = abs(old), anew = abs(nw);
            if ((aold % 2 == 1) && (anew % 2 == 0)) {
                sumEven += nw;
            } else if ((aold % 2 == 0) && (anew % 2 == 1)) {
                sumEven -= old;
            } else if ((aold % 2 == 0) && (anew % 2 == 0)) {
                sumEven += val;
            }
            ans.push_back(sumEven);
            nums[index] += val;
        }
        return ans;
    }
};