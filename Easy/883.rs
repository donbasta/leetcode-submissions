use std::cmp::max;

impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut area: i32 = 0;
        for i in 0..n {
            for j in 0..n {
                if grid[i as usize][j as usize] > 0 {
                    area += 1;
                }
            }
        }
        for j in 0..n {
            let mut mx_col = 0;
            for i in 0..n {
                mx_col = max(mx_col, grid[i as usize][j as usize]);
            }
            area += mx_col;
        }
        for i in 0..n {
            let mut mx_row = 0;
            for j in 0..n {
                mx_row = max(mx_row, grid[i as usize][j as usize]);
            }
            area += mx_row;
        }
        area
    }
}