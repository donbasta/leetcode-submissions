class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for(int i = 1; i < (int)target.size(); i++) {
            ans += max(0, target[i] - target[i - 1]);
        }
        return ans;
    }
};