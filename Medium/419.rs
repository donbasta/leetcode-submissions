impl Solution {
    pub fn count_battleships(board: Vec<Vec<char>>) -> i32 {
        let m: i32 = board.len() as i32;
        let n: i32 = board[0].len() as i32;
        let mut vis: Vec<Vec<bool>> = vec![vec![false; n as usize]; m as usize];
        let mut ans = 0;
        let dir: Vec<Vec<i32>> = vec![vec![1, 0], vec![-1, 0], vec![0, 1], vec![0, -1]];
        for i in 0..m {
            for j in 0..n {
                let ii = i as usize;
                let jj = j as usize;
                if board[ii][jj] == '.' { continue; }
                if vis[ii][jj] { continue; }
                ans += 1;
                vis[ii][jj] = true;
                let mut stack: Vec<Vec<i32>> = Vec::new();
                stack.push(vec![i, j]);
                while stack.len() > 0 {
                    let now = stack.pop().unwrap();
                    for k in 0..4 {
                        let ni = now[0] + dir[k][0];
                        let nj = now[1] + dir[k][1];
                        if ni < 0 || ni >= m || nj < 0 || nj >= n { continue; }
                        if board[ni as usize][nj as usize] == '.' { continue; }
                        if vis[ni as usize][nj as usize] { continue; }
                        vis[ni as usize][nj as usize] = true;
                        stack.push(vec![ni, nj]);
                    }
                }
            }
        }
        ans
    }
}