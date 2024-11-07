class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int i = 0, j = numbers.size() - 1;
        while (numbers[i] + numbers[j] != target) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            }
        }
        ans[0] = i + 1, ans[1] = j + 1;
        return ans;
    }
};