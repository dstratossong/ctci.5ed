#include <iostream>
#include <sstream>

using namespace std;

string compress(string& str) {
  if (str.length() == 0) {
    return str;
  }

  ostringstream builder;
  char current = str[0];
  int counter = 1;

  for (int i = 1; i < str.length(); i++) {
    if (str[i] == current) {
      counter++;
    } else {
      builder << current << counter;
      current = str[i];
      counter = 1;
    }
  }

  builder << current << counter;

  string compressed = builder.str();
  
  if (compressed.length() < str.length()) {
    return compressed;
  } else {
    return str;
  }
}

int main() {
  string str;
  getline(cin, str);

  cout << compress(str) << endl;

  return 0;
}
