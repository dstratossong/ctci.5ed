/**
 *  Author: Arshan Alam
 *  Date: 20160925
 *
 *  Solution to "Cracking the Coding Interview 6e" (CTCI.6e) problem 1.1
 *
 *  isUnique
 *
 *  Implement an algorithm to determine if a a string has all unique
 *  characters. What if you cannot use additional data structures?
 *
 */

 #include <iostream>


/*
 * isUnique
 *
 * Determine if the given string 'str' contains unique characters.
 *
 * Assumptions: String contains Standard ASCII characters, and uppercase
 * characters are not equivalent to their lowercase counterpart.
 *
 * str : string
 **/
bool isUnique(std::string & str) {
  const int  NUM_ASCII_CHAR = 128;

  /* If the length of the string is more than NUM_ASCII_CHAR, then
   * the string must have an ASCII character that repeats.
   */
  if (str.length() > NUM_ASCII_CHAR) {
    return false;
  }
  bool dupCheckMap[NUM_ASCII_CHAR] = { false };
  for (char & c : str) {
    // NOTE: A char in c++ has value <= NUM_ASCII_CHAR
    if(dupCheckMap[c] == true) {
      return false;
    }
    dupCheckMap[c] = true;
  }
  return true;
}

/*
 * Read input string from the default input stream and output whether the
 * string contains unique characters.
 **/
int main() {
  std::string s;
  std::cin >> s;
  std::cout << isUnique(s) << std::endl;
  return 0;
}
