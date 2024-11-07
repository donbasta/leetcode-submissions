use std::cmp::max;

impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let n: i32 = grid.len() as i32;
        let dir: Vec<(i32, i32)> = vec![(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut ans: i32 = 0;
        for i in 0..n {
            for j in 0..n {
                for k in 0..4 {
                    let ni: i32 = i + dir[k as usize].0;
                    let nj: i32 = j + dir[k as usize].1;
                    if ni < 0 || ni >= n || nj < 0 || nj >= n {
                        ans += grid[i as usize][j as usize];
                    } else {
                        ans += max(0, grid[i as usize][j as usize] - grid[ni as usize][nj as usize]);
                    }
                }
                if grid[i as usize][j as usize] > 0 {
                    ans += 2;
                }
            }
        }
        return ans;
    }
}