class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> de;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            while (!de.empty() && de.back().second < nums[i]) {
                de.pop_back();
            }
            de.push_back(make_pair(i, nums[i]));
        }
        res.push_back(de.front().second);
        for (int i = k; i < n; i++) {
            if (de.front().first == i - k) de.pop_front();
            while (!de.empty() && de.back().second < nums[i]) {
                de.pop_back();
            }
            de.push_back(make_pair(i, nums[i]));
            res.push_back(de.front().second);
        }
        return res;
    }
};