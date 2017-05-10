#include <iostream>
#include <map>

using namespace std;

bool is_permutation(string& str1, string& str2) {
  if (str1.length() != str2.length()) {
    return false;
  }

  map<char, int> char_map;

  // increment
  for (int i = 0; i < str1.length(); i++) {
    if (char_map.find(str1[i]) != char_map.end()) {
      char_map[str1[i]]++;
    } else {
      char_map[str1[i]] = 1;
    }
  }

  // decrement
  for (int i = 0; i < str2.length(); i++) {
    if (char_map.find(str2[i]) != char_map.end()) {
      char_map[str2[i]]--;
    } else {
      return false;
    }
  }

  // check
  map<char, int>::iterator it = char_map.begin();
  
  while (it != char_map.end()) {
    if (it->second != 0) {
      return false;
    }
    it++;
  }

  return true;
}

int main() {
  string str1, str2;
  
  getline(cin, str1);
  getline(cin, str2);

  if (is_permutation(str1, str2)) {
    cout << "anagram" << endl;
  } else {
    cout << "not anagram" << endl;
  }

  return 0;
}
