impl Solution {
    pub fn flip_and_invert_image(image: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = image.len();
        let n = image[0].len();
        let mut ret = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                ret[i][j] = 1 - image[i][n - 1 - j];
            }
        }
        ret
    }
}