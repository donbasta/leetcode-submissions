impl Solution {
    pub fn to_lowercase(c: char) -> char {
        if c.is_ascii() && c.is_ascii_uppercase() {
            ((c as u8) + 32) as char
        } else {
            c
        }
    }

    pub fn make_good(s: String) -> String {
        let n = s.len();
        let cs: Vec<char> = s.chars().collect();
        let mut st: Vec<char> = Vec::new();
        st.push(cs[0]);
        let mut ptr = 1;
        while ptr < n {
            let cur: char = cs[ptr];
            if st.len() == 0 {
                st.push(cur);
            } else if Self::to_lowercase(cur) == Self::to_lowercase(st[st.len() - 1]) && cur != st[st.len() - 1] {
                st.pop();
            } else {
                st.push(cur);
            }
            ptr += 1;
        }
        return st.into_iter().collect();
    }
}