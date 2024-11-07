class Solution {
public:
    int maximumSwap(int num) {
        int ptr = 0;
        string snum = to_string(num);
        int n = snum.size();
        while (ptr < n && snum[ptr] == *max_element(snum.begin() + ptr, snum.end())) ptr++;
        if (ptr == n) return num;
        int mx_idx = n - 1;
        int mx = *max_element(snum.begin() + ptr, snum.end());
        while (snum[mx_idx] != mx) mx_idx--;
        assert (mx_idx > ptr);
        swap(snum[ptr], snum[mx_idx]);
        return stoi(snum);
    }
};