class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 1, j = n - 2;
        // if (arr == vector<int>{0,1,2,3,4,5,6,7,8,9}) return false;
        while (i < n && arr[i] > arr[i - 1]) {
            i++;
        }
        while (j >= 0 && arr[j] > arr[j + 1]) {
            j--;
        }
        // cout << i << ' ' << j << '\n';
        return (i - 1 == j + 1 && i >= 2 && j <= n - 3);
    }
};