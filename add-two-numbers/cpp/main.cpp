#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *sol = new ListNode();
    ListNode *current = sol;
    int carry = 0;
    while (l1 || l2 || carry) {
      int value = carry;
      if (l1) {
        value += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        value += l2->val;
        l2 = l2->next;
      }
      carry = value / 10;
      value = value % 10;
      current->val = value;
      
      // Only create next node if we need it
      if (l1 || l2 || carry) {
        current->next = new ListNode();
        current = current->next;
      }
    }
    return sol;
  }
};

// This is boilerplate to be able to test locally
int main() {
  // Test case: 342 + 465 = 807
  // Represented as: [2,4,3] + [5,6,4] = [7,0,8]

  // Create first number: 342 -> [2,4,3]
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  // Create second number: 465 -> [5,6,4]
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  // Test the solution
  Solution solution;
  ListNode *result = solution.addTwoNumbers(l1, l2);

  // Print result
  std::cout << "Result: ";
  ListNode *current = result;
  while (current) {
    std::cout << current->val;
    current = current->next;
    if (current)
      std::cout << " -> ";
  }
  std::cout << std::endl;

  return 0;
}
