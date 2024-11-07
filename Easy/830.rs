impl Solution {
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let mut st: i32 = 0;
        let chars: Vec<char> = s.chars().collect();
        let n: i32 = chars.len() as i32;
        let mut cur_char = chars[0];

        let mut ret: Vec<Vec<i32>> = Vec::new();

        for i in 1..n {
            if chars[i as usize] != cur_char {
                if i - st >= 3 {
                    ret.push(vec![st, i - 1]);
                }
                st = i;
                cur_char = chars[i as usize];
            }
        }
        if n - st >= 3 {
            ret.push(vec![st, n - 1]);
        }
        ret
    }
}