impl Solution {
    pub fn compute_area(ax1: i32, ay1: i32, ax2: i32, ay2: i32, bx1: i32, by1: i32, bx2: i32, by2: i32) -> i32 {
        let mut isect_area: i32;
        if ax1 >= bx2 || bx1 >= ax2 || ay1 >= by2 || by1 >= ay2 {
            isect_area = 0;
        } else {
            use std::cmp::min;
            use std::cmp::max;    
            isect_area = (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
        }
        (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - isect_area
    }
}