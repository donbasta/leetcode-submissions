impl Solution {
    pub fn max_count(m: i32, n: i32, ops: Vec<Vec<i32>>) -> i32 {
        let count_ops = ops.len();
        if count_ops == 0 {
            return m * n;
        }
        let mut a = i32::pow(10, 9);
        let mut b = i32::pow(10, 9);
        use std::cmp;
        for i in 0..count_ops {
            a = cmp::min(a, ops[i][0]);
            b = cmp::min(b, ops[i][1]);
        }
        a * b
    }
}