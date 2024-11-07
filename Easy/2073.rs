impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        let mut time = 0;
        let mut remainder = tickets.clone();
        for i in 1..101 {
            for idx in 0..remainder.len() {
                if remainder[idx] > 0 {
                    remainder[idx] -= 1;
                    time += 1;
                    if remainder[idx] == 0 && idx == k as usize {
                        return time;
                    }
                }
            }
        }
        -1
    }
}