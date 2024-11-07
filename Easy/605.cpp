class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        bool cant = false;
        int add = 0;
        for (int i = 0; i < sz; i++) {
            if (flowerbed[i] == 1) {
                cant = true;
            } else {
                if (cant) {
                    cant = false;
                } else {
                    if ((i < sz - 1 && flowerbed[i + 1] != 1) || (i == sz - 1)) {
                        add++;
                        cant = true;
                    }
                }
            }
        }
        return add >= n;
    }
};