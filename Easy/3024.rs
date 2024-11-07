impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        let mx = nums.iter().max().unwrap();
        let mut ans = String::new();
        if nums[0] + nums[1] + nums[2] <= mx * 2 {
            ans.push_str("none");
        } else if nums[0] == nums[1] && nums[0] == nums[2] {
            ans.push_str("equilateral");
        } else if nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2] {
            ans.push_str("isosceles");
        } else {
            ans.push_str("scalene");
        }
        return ans;
    }
}