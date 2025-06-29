struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();

        let mut dp = vec![vec![false; n]; n];
        for i in 0..n {
            dp[i][i] = true;
        }
        let mut maxLen = 1;
        let mut start = 0;
        
        for i in 0..n - 1 {
            if chars[i] == chars[i + 1] {
                dp[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }
        
        for len in 3..=n {
            for i in 0..n - len + 1 {
                let j = i + len - 1;
                if chars[i] == chars[j] && dp[i + 1][j - 1] {
                    dp[i][j] = true;
                    maxLen = len;
                    start = i;
                }
            }
        }
        
        String::from(&s[start..start + maxLen])
    }
}

fn main() {
    let s = String::from("babad");
    let result = Solution::longest_palindrome(s);
    println!("Longest palindrome: {}", result);
}
