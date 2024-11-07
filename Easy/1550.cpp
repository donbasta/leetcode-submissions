class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] & 1) cur++;
            else cur = 0;
            if (cur == 3) return true;
        }
        return false;
    }
};