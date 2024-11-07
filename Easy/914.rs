use std::collections::HashMap;

impl Solution {
    pub fn fpb(mut a: i32, mut b: i32) -> i32 {
        if a < b {
            (a, b) = (b, a);
        }
        if b == 0 {
            return a;
        }
        return Self::fpb(b, a % b);
    }

    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for d in deck.iter() {
            *cnt.entry(*d).or_insert(0) += 1;
        }
        let mut gcd = 0;
        for (_, val) in &cnt {
            gcd = Self::fpb(gcd, *val);
        }
        return gcd > 1;
    }
}