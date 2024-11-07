class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int residue_class[value];
        memset(residue_class, 0, sizeof(residue_class));
        for (auto e : nums) {
            int sisa = e % value;
            if (sisa < 0) sisa += value;
            residue_class[sisa]++;
        }
        int mn = *min_element(residue_class, residue_class + value);
        for (int i = 0; i < value; i++) {
            if (residue_class[i] == mn) {
                return mn * value + i;
            } 
        }
        return -1;
    }
};