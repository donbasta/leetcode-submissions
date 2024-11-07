impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut binary: Vec<i32> = Vec::new();
        let mut cn = n;
        let mut last = -1;
        let mut cur = -1;
        let mut ans = 0;
        while cn > 0 {
            cur += 1;
            if cn % 2 == 1 {
                if last != -1 {
                    ans = std::cmp::max(cur - last, ans);
                }
                last = cur;
            }
            cn /= 2;
        }
        ans
    }
}