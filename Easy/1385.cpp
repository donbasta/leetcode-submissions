class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        int itr = 0;
        for (auto c : arr1) {
            while (itr < arr2.size() && arr2[itr] < c) ++itr;
            bool ok = true;
            if (itr < arr2.size() && arr2[itr] - c <= d) ok = false;
            if (itr > 0 && c - arr2[itr - 1] <= d) ok = false;
            ans += ok;
        }
        return ans;   
    }
};