class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> ve(51);
        int buang = 0;
        while (!nums.empty()) {
            ve[nums.back()] = true;
            buang++;
            int cnt = 0;
            for (int i = 1; i <= k; i++) {
                cnt += ve[i];
            }
            if (cnt == k) {
                return buang;
            }
            nums.pop_back();
        }
        return -1;
    }
};