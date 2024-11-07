class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        int n = m / 2;
        for (int i = 1; i <= n; i++) {
            if (nums[0] == nums[i]) continue;
            if (((nums[0] + nums[i]) % 2) != 0) continue;
            int k = (nums[i] - nums[0]) / 2;
            multiset<int> se;
            for (auto e : nums) se.insert(e);
            vector<int> tmp;
            bool cant = false;
            while (!se.empty()) {
                int cur = *se.begin();
                if (se.find(cur + k * 2) == se.end()) {
                    cant = true;
                    break;
                } else {
                    se.erase(se.find(cur)), se.erase(se.find(cur + k * 2));
                    tmp.push_back(cur + k);
                }
            }
            if (cant) continue;
            else return tmp;
        }
        return {};
    }
};