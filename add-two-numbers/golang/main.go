package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var sol *ListNode = new(ListNode)
	// Equivalence of &ListNode{}
	current := sol
	carry := 0
	// There is no while in Go
	for l1 != nil || l2 != nil || carry != 0 {
		value := carry
		if l1 != nil {
			value += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			value += l2.Val
			l2 = l2.Next
		}
		carry = value / 10
		value = value % 10
		current.Val = value

		// Only create next node if we need it
		if l1 != nil || l2 != nil || carry != 0 {
			current.Next = new(ListNode)
			current = current.Next
		}
	}
	return sol
}

// This is boilerplate to be able to test locally
func main() {
	// Test case: [2,4,3] + [5,6,4] = [7,0,8]
	// Represents 342 + 465 = 807
	l1 := &ListNode{Val: 2, Next: &ListNode{Val: 4, Next: &ListNode{Val: 3}}}
	l2 := &ListNode{Val: 5, Next: &ListNode{Val: 6, Next: &ListNode{Val: 4}}}

	result := addTwoNumbers(l1, l2)

	// Print result (expected: 7 -> 0 -> 8)
	fmt.Print("Result: ")
	current := result
	for current != nil {
		fmt.Print(current.Val)
		if current.Next != nil {
			fmt.Print(" -> ")
		}
		current = current.Next
	}
	fmt.Println()
}
