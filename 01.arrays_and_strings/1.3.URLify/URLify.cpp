/**
 *  Arshan Alam
 *
 *  Solution to problem CTCI 6th Edition problem 1.3
 *
 *  URLify
 *
 *  Write a method to replace all spaces in a string with '%20'.
 *
 *  Assume input string has sufficient space at the end to
 *  hold the additional characters, and that the "true" length of the
 *  string is given.
 *
 */

#include <iostream>

int ASCII_SPACE_NUM = 32;

/**
 *  Replace all spaces in a string with '%20'
 *
 *  Running Time: In place Theta(n) where n is the true length of string
 *
 * str: String to modify
 *
 * trueLen: Number of actual characters in the string
 */
void URLify(std::string & str, int trueLen) {
  if(trueLen == 0) {
    return;
  }

  int curPos = str.length();

  for(int i = trueLen-1; i >= 0; i--) {
    char cur = str[i];
    if(cur == ASCII_SPACE_NUM) {
      str[--curPos] = '0';
      str[--curPos] = '2';
      str[--curPos] = '%';
    } else {
      str[--curPos] = cur;
    }
  }
}

int main() {
  std::string str;
  int trueLen;
  std::getline(std::cin, str);
  std::cin >> trueLen;
  URLify(str, trueLen);
  std::cout << str << std::endl;
  return 0;
}
