impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut tmp = 0;
        let mut ans = 0;
        for c in s.chars() {
            if c == '(' {
                tmp += 1;
            } else if c == ')' {
                tmp -= 1;
            }
            ans = std::cmp::max(ans, tmp);
        }
        assert_eq!(tmp, 0);
        ans
    }
}