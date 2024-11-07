/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 1, r = n - 2;
        int pivot;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = mountainArr.get(mid), y = mountainArr.get(mid + 1);
            if (x < y) {
                l = mid + 1;
            } else if (x > y) {
                pivot = mid;
                r = mid - 1;
            }
        }
        l = 0, r = pivot;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = mountainArr.get(mid);
            if (x < target) {
                l = mid + 1;
            } else if (x > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        l = pivot, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = mountainArr.get(mid);
            if (x < target) {
                r = mid - 1;
            } else if (x > target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};