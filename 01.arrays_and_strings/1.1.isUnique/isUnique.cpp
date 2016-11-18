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

const int  NUM_ASCII_CHAR = 128;

/*
 * isUnique
 *
 * Determine if the given string 'str' contains unique characters.
 *
 * Running time Theta(n) where n is the length of the string
 *
 * Assumptions: String contains Standard ASCII characters, and uppercase
 * characters are not equivalent to their lowercase counterpart.
 *
 * str : string
 **/
bool isUnique(std::string & str) {
  /* If the length of the string is more than NUM_ASCII_CHAR, then
   * the string must have an ASCII character that repeats.
   */
  if (str.length() > NUM_ASCII_CHAR) {
    return false;
  } else if(str.length() <= 1) {
    return true;
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
 * Bubble down str[i] based on a
 * min-heap approach.
 *
 * We only bubble down when str[i] is greater than
 * the left and right child.
 *
 * str  : string to heapify
 * i    : index
 **/
void bubbleDown(std::string & str, int i) {
  int left;
  int right;
  char cur;
  char leftVal;
  char rightVal;
  int len = str.length();
  while(true) {
    left = 2*i + 1;   // left child
    right = 2*i + 2;  // right child
    cur = str[i];
    leftVal = cur;
    rightVal = cur;

    if(left < len) {
      leftVal = str[left];
    }

    if(right < len) {
      rightVal = str[right];
    }

    if(leftVal < rightVal) {
      if(cur > leftVal) {
        str[i] = leftVal;
        str[left] = cur;
        i = left;
      } else {
        return; // can't bubble down anymore
      }
    } else {
      if(cur > rightVal) {
        str[i] = rightVal;
        str[right] = cur;
        i = right;
      } else {
        return; // can't bubble down anymore
      }
    }
  } // end of while loop
}

/*
 * Create a min-heap (in-place).
 *
 * str : string to heapify
 **/
void heapify(std::string & str) {
  // start the bottom-up heapify from the second last level
  // because the last level cannot be bubbled-down
  //
  // We subtract 1 in case if the length of str == 1
  int n = (str.length() - 1)/2;

  for(int i = n; i >= 0; i--) {
    bubbleDown(str, i);
  }
}

/**
 * Delete the minimum value of from the heapified string.
 *
 * str: Non empty string
 */
char deleteMin(std::string & str) {
  char c = str[0];
  int len = str.length();
  if(len > 1) {
    str[0] = str[len-1];
    str[len-1] = c;
    str.erase(str.end()-1);
    bubbleDown(str, 0);
  } else {
    str.clear();
  }
  return c;
}



 /*
  * isUniqueInPlace
  *
  * This algorithm determines if the string 'is unique' without using
  * additional data structures.
  *
  * Running time Theta(n + klogn) where n is the length of the string and
  * k is the number of iterations taken to find two of the same character.
  *
  * Note: Worst case running time Theta(nlogn)
  *
  * Determine if the given string 'str' contains unique characters.
  *
  * Assumptions: String contains Standard ASCII characters, and uppercase
  * characters are not equivalent to their lowercase counterpart.
  *
  * str : string
  **/
bool isUniqueInPlace(std::string & str) {
  char prevChar, curChar;
  bool completedFirstIteration = false;

  /* If the length of the string is more than NUM_ASCII_CHAR, then
   * the string must have an ASCII character that repeats.
   */
  if (str.length() > NUM_ASCII_CHAR) {
    return false;
  } else if(str.length() <= 1) {
    return true;
  }

  heapify(str);

  while(str.length() > 0) {
    curChar = deleteMin(str);

    if(!completedFirstIteration) {
      completedFirstIteration = true;
      prevChar = curChar;
      continue;
    }

    if(curChar == prevChar) {
      return false;
    } else {
      prevChar = curChar;
    }
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
  std::cout << isUniqueInPlace(s) << std::endl;
  return 0;
}
