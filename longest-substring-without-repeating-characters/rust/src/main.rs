use std::{cmp::max, collections::HashMap};

struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut sol: i32 = 0;
        let mut left = 0;
        let mut last_index: HashMap<char, usize> = HashMap::new();
        for (right, c) in s.chars().enumerate() {
            if let Some(&index) = last_index.get(&c) {
                if index >= left {
                    left = index + 1;
                }
            }
            last_index.insert(c, right);
            sol = max(sol, (right - left + 1) as i32);
        }
        sol
    }
}

// This is boilerplate to be able to test locally in VS Code
fn main() {
    println!("{}", Solution::length_of_longest_substring("teteeste".to_string()));
}
