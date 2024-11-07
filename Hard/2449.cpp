class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<vector<int>> targetParity(2), numsParity(2);
        for (int i = 0; i < n; i++) {
            numsParity[nums[i] & 1].push_back(nums[i]);
            targetParity[target[i] & 1].push_back(target[i]);
        }
        for (int i = 0; i < 2; i++) {
            sort(numsParity[i].begin(), numsParity[i].end());
            sort(targetParity[i].begin(), targetParity[i].end());
        }
        long long step = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < numsParity[i].size(); j++) {
                step += max(targetParity[i][j] - numsParity[i][j], 0);
            }
        }
        return step / 2;
    }
};