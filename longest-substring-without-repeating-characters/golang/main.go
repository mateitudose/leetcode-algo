package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	sol, left := 0, 0
	// Go string is made of bytes, not runes!
	lastIndex := make(map[byte]int)
	for right := 0; right < len(s); right++ {
		c := s[right]
		if index, exists := lastIndex[c]; exists && index >= left {
			left = index + 1
		}
		lastIndex[c] = right
		sol = max(sol, right - left + 1)
	}
	return sol
}

// This is boilerplate to be able to test locally
func main() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
}
