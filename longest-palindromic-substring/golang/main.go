package main

import (
	"fmt"
)

func longestPalindrome(s string) string {
	dp := make([][]int, len(s))
	// Inner slices are nil
	for i := range dp {
		dp[i] = make([]int, len(s))
	}
	for i := 0; i < len(s); i++ {
		dp[i][i] = 1
	}
	maxLen := 1
	start := 0
	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			dp[i][i+1] = 1
			maxLen = 2
			start = i
		}
	}
	for length := 3; length <= len(s); length++ {
		for i := 0; i < len(s)-length+1; i++ {
			j := i + length - 1
			if s[i] == s[j] && dp[i+1][j-1] != 0 {
				dp[i][j] = 1
				maxLen = length
				start = i
			}
		}
	}
	return s[start : start+maxLen]
}

func main() {
	input := "babad"
	result := longestPalindrome(input)
	fmt.Println("Longest Palindromic Substring:", result)
}
