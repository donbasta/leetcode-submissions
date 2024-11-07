/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int L = 1, R = n;
        int ans = -1;
        while (L <= R) {
            int mid = (1ll * L + R) >> 1;
            int x = guess(mid);
            if (x == -1) {
                R = mid - 1;
            } else if (x == 1) {
                L = mid + 1;
            } else {
                return mid;
            }
        }
        return ans;
    }
};