/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.2 Check Permutation
 *
 * Given two strings, write a method to decide if
 * one is a permutation of the other.
 *
 */
#include <iostream>

const int NUM_STANDARD_ASCII_CHAR = 128;

/**
 * Check if string s2 is a permutation of string s1.
 *
 * Assumption: s1 and s2 only contain standard ASCII characters.
 *
 * Running time is Theta(n)
 *
 */
bool checkPermutation(std::string & s1, std::string & s2) {
  // if the strings don't have the same length, they cannot be permutations
  // of each other.
  if(s1.length() != s2.length()) {
    return false;
  }

  /*
   * The general idea behind this algorithm is to exploit that each character in
   * s1 and s2 have values between 0 <= c < NUM_STANDARD_ASCII_CHAR.
   *
   * Thus create a hashmap counter that counts the number of occurences of
   * character c.
   *
   * Lastly, iterate through s1CharMap and s2CharMap to confirm that they
   * are equal.
   *
   **/
  int * s1CharMap[NUM_STANDARD_ASCII_CHAR] = { 0 };
  int * s2CharMap[NUM_STANDARD_ASCII_CHAR] = { 0 };
  int len = s1.length();

  for(int i = 0; i < len; i++) {
    s1CharMap[s1[i]]++;
    s2CharMap[s2[i]]++;
  }

  for(int i = 0; i < NUM_STANDARD_ASCII_CHAR; i++) {
    if(s1CharMap[i] != s2CharMap[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string s1;
  std::string s2;
  std::cin >> s1 >> s2;
  std::cout << checkPermutation(s1, s2) << std::endl;
  return 0;
}
