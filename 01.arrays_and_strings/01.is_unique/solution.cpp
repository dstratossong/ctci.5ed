#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Uses a std::map
// Complexity O(n)
bool is_unique(const string& str) {
  map<char, bool> char_map;

  for (int i = 0; i < str.length(); i++) {
    if (char_map.find(str[i]) != char_map.end()) {
      return false;
    } else {
      char_map[str[i]] = true;
    }
  }

  return true;
}

// Sorts string
// Complexity O(n log n)
bool is_unique_in_place(string str) {
  sort(str.begin(), str.end());

  for (int i = 1; i < str.length(); i++) { 
    if (str[i-1] == str[i]) {
      return false;
    }
  }

  return true;
}

// Uses an array instead of map
// Assumes we are getting std ascii string
// Uses more memory for small inputs
// but gets rid of overhead
// Complexity O(n)
bool is_unique_ascii(const string& str) {
  bool char_map[128] = { false };

  for (int i = 0; i < str.length(); i++) {
    if (char_map[str[i]] == true) {
      return false;
    } else {
      char_map[str[i]] = true;
    }
  }

  return true;
}


int main() {

  string line;
  getline(cin, line);

  if (is_unique(line)) {
    cout << "unique" << endl;
  } else {
    cout << "not unique" << endl;
  }

  if (is_unique_in_place(line)) {
    cout << "unique" << endl;
  } else {
    cout << "not unique" << endl;
  }

  if (is_unique_ascii(line)) {
    cout << "unique" << endl;
  } else {
    cout << "not unique" << endl;
  }

  return 0;
}
