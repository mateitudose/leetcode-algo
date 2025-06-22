use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut index_of: HashMap<i32, usize> = HashMap::new();
        for (index, number) in nums.iter().enumerate() {
            let complement: i32 = target - *number;
            if index_of.contains_key(&complement) {
                let prev_index: i32 = *index_of.get(&complement).unwrap() as i32;
                return vec![prev_index, index as i32];
            }
            index_of.insert(*number, index);
        }
        vec![]
    }
}

// This is boilerplate to be able to test locally in VS Code
fn main() {
    // Test the function manually
    let nums = vec![2, 7, 11, 15];
    let target = 9;
    let result = Solution::two_sum(nums.clone(), target);
    println!("Input: nums={:?}, target={}", nums, target);
    println!("Output: {:?}", result);
}