struct StockSpanner {
    st: Vec<(i32, i32)>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {
    fn new() -> Self {
        Self {st: Vec::new()}
    }
    fn next(&mut self, price: i32) -> i32 {
        let mut part = 1;
        while !self.st.is_empty() && self.st.last().unwrap().0 <= price {
            part += self.st.last().unwrap().1;
            self.st.pop();
        }
        self.st.push((price, part));
        return part;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner::new();
 * let ret_1: i32 = obj.next(price);
 */
