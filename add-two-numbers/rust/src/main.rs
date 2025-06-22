#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub struct Solution;

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut sol = Some(Box::new(ListNode::new(0)));
        let mut current = &mut sol;
        let mut l1_mut = l1;
        let mut l2_mut = l2;
        let mut carry = 0;
        while l1_mut.is_some() || l2_mut.is_some() || carry > 0 {
            let mut value = carry;
            if let Some(node) = l1_mut.as_ref() {
                value += node.val;
                l1_mut = l1_mut.unwrap().next;
            }
            if let Some(node) = l2_mut.as_ref() {
                value += node.val;
                l2_mut = l2_mut.unwrap().next;
            }
            carry = value / 10;
            value = value % 10;
            current.as_mut().unwrap().val = value;

            // Only create next node if we need it
            if l1_mut.is_some() || l2_mut.is_some() || carry > 0 {
                current.as_mut().unwrap().next = Some(Box::new(ListNode::new(0)));
                current = &mut current.as_mut().unwrap().next;
            }
        }
        sol
    }
}

// This is boilerplate to be able to test locally
fn main() {
    // Test case: [2,4,3] + [5,6,4] = [7,0,8]
    // Represents 342 + 465 = 807
    let l1 = Some(Box::new(ListNode {
        val: 2,
        next: Some(Box::new(ListNode {
            val: 4,
            next: Some(Box::new(ListNode::new(3))),
        })),
    }));

    let l2 = Some(Box::new(ListNode {
        val: 5,
        next: Some(Box::new(ListNode {
            val: 6,
            next: Some(Box::new(ListNode::new(4))),
        })),
    }));

    let result = Solution::add_two_numbers(l1, l2);

    // Print result (expected: 7 -> 0 -> 8)
    print!("Result: ");
    let mut current = result.as_ref();
    while let Some(node) = current {
        print!("{}", node.val);
        if node.next.is_some() {
            print!(" -> ");
        }
        current = node.next.as_ref();
    }
    println!();
}
