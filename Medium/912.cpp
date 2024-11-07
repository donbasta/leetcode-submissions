class Solution {
public:
    vector<int> buf;

    void sortUtil(int l, int r, vector<int>& nums) {
        if (l == r) return;
        int mid = (l + r) >> 1;
        sortUtil(l, mid, nums);
        sortUtil(mid + 1, r, nums);
        int i = l, j = mid + 1;
        int ptr = 0;
        while (i <= mid || j <= r) {
            if (i > mid) buf[ptr++] = (nums[j++]);
            else if (j > r) buf[ptr++] = (nums[i++]);
            else if (nums[i] < nums[j]) buf[ptr++] = (nums[i++]);
            else buf[ptr++] = (nums[j++]);
        }
        for (int i = 0; i < ptr; i++) {
            nums[i + l] = buf[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        buf.resize(n);

        sortUtil(0, n - 1, nums);
        return nums;
    }
};