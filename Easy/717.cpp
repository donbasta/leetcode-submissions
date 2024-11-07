class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int itr = 0;
        while (itr < n) {
            if (bits[itr] == 0) { 
                itr++;
                if (itr == n) return true;
            } else {
                if (itr == n - 1) return false;
                itr += 2;
            }
        }
        return false;
    }
};