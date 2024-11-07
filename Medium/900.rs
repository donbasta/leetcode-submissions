struct RLEIterator {
    ptr: i64, 
    prefix: Vec<(i64, i32)>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RLEIterator {

    fn new(encoding: Vec<i32>) -> Self {
        let mut cur_sum: i64 = 0;
        let mut pref : Vec<(i64, i32)> = Vec::new();
        let sz = encoding.len();
        for i in (0..sz - 1).step_by(2) {
            cur_sum += encoding[i] as i64;
            pref.push((cur_sum, encoding[i + 1]));
        }
        Self {ptr: 0, prefix: pref}
    }

    fn next(&mut self, n: i32) -> i32 {
        self.ptr += n as i64;
        let mut lo = 0 as i32;
        let mut hi = self.prefix.len() as i32 - 1;
        let mut ans = -1;
        while lo <= hi {
            let mid = (lo + hi) / 2;
            if self.prefix[mid as usize].0 >= self.ptr {
                ans = self.prefix[mid as usize].1;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * let obj = RLEIterator::new(encoding);
 * let ret_1: i32 = obj.next(n);
 */