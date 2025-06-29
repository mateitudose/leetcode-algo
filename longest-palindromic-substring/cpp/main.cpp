#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int dp[s.length()][s.length()];

    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < s.length(); j++) {
        if (i != j)
          dp[i][j] = 0;
        else
          dp[i][j] = 1;
      }
    }
    int maxLen = 1;
    int start = 0;
    // Check for palindromes of length 2
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 1;
        maxLen = 2;
        start = i;
      }
    }
    for (int len = 3; len <= s.length(); len++) {
      for (int i = 0; i < s.length() - len + 1; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = 1;
          maxLen = len;
          start = i;
        }
      }
    }
    return s.substr(start, maxLen);
  }
};

// This is boilerplate to be able to test locally in VS Code
int main() {
  Solution solution;
  string input = "babad";
  string result = solution.longestPalindrome(input);
  cout << "Longest Palindromic Substring: " << result << endl;
  return 0;
}
