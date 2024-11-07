impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut pos: Vec<(usize, usize)> = vec![(0, 0); m * n + 1];
        let mut row: Vec<i32> = vec![0; m];
        let mut col: Vec<i32> = vec![0; n];
        for i in 0..m {
            for j in 0..n {
                pos[mat[i][j] as usize] = (i, j);
            }
        }
        for i in 0..arr.len() {
            row[pos[arr[i] as usize].0] += 1;
            col[pos[arr[i] as usize].1] += 1;
            if row[pos[arr[i] as usize].0] == n as i32 || col[pos[arr[i] as usize].1] == m as i32 {
                return i as i32;
            } 
        }
        -1
    }
}