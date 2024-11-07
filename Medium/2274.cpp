class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        int prv = bottom - 1;
        sort(special.begin(), special.end());
        for (int i = 0; i < special.size(); i++) {
            ans = max(ans, special[i] - 1 - prv);
            prv = special[i];
        }
        ans = max(ans, top - prv);
        return ans;
    }
};