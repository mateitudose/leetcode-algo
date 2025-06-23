#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int sol = 0, left = 0;
    unordered_map<char, int> lastIndex;
    for (int right = 0; right < s.size(); right++) {
      char c = s[right];
      if (lastIndex.count(c) && lastIndex.at(c) >= left) {
        left = lastIndex[c] + 1;
      }
      lastIndex[c] = right;
      sol = max(sol, right - left + 1);
    }
    return sol;
  }
};

// This is boilerplate to be able to test locally
void testCase(string input, int expected, string description) {
  Solution solution;
  int result = solution.lengthOfLongestSubstring(input);
  cout << "Test: " << description << endl;
  cout << "Input: \"" << input << "\"" << endl;
  cout << "Expected: " << expected << ", Got: " << result << endl;
  assert(result == expected);
  cout << "PASSED" << endl << endl;
}

int main() {
  cout << "Testing Longest Substring Without Repeating Characters" << endl;
  cout << "======================================================" << endl
       << endl;

  // Test cases
  testCase("abcabcbb", 3, "Basic case with repeating pattern");
  testCase("bbbbb", 1, "All same characters");
  testCase("pwwkew", 3, "Mixed repeating characters");
  testCase("", 0, "Empty string");
  testCase("au", 2, "Two different characters");
  testCase("dvdf", 3, "Another mixed case");

  cout << "All tests completed!" << endl;
  return 0;
}
