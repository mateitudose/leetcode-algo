package main

import "fmt"

func twoSum(nums []int, target int) []int {
	indexOf := make(map[int]int)
	for index, num := range nums {
		val, present := indexOf[target-num]
		// Fun fact: () are optional for ifs in Go!
		if present {
			return []int{val, index}
		}
		indexOf[num] = index
	}
	return []int{}
}

// This is boilerplate to be able to test locally in VS Code
func main() {
	// Test the function manually
	nums := []int{2, 7, 11, 15}
	target := 26
	result := twoSum(nums, target)
	fmt.Printf("Input: nums=%v, target=%d\n", nums, target)
	fmt.Printf("Output: %v\n", result)
}
