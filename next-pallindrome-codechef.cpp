// https://www.codechef.com/problems/PALIN

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkifpallindrome(string str) {
  string rev = str;
  reverse(rev.begin(), rev.end());
  return str.compare(rev) == 0;
}

string checkifAll9s(string str) {
  bool all9s = true;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] != '9') {
      all9s = false;
      return str;
    }
  }
  for (int i = 0; i < str.length(); i++) str[i] = '0';
  str.insert(0,"1");
  return str;
}

string increment(int index, string str) {
  if (((int)str[index - 1]-48) == 9) {
    if (index - 1 == 0) {
      str.insert(0, "1");
      /* code */
    }
    str = increment(index - 1, str);
    return str;
  }
  str[index - 1] = (char)(((int)str[index-1] - 47) + 48);
  return str;
}

int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {

    string str;
    cin >> str;
    string original = str;
    str = checkifAll9s(str);

    int i = str.length() % 2 == 0 ? str.length()/2 - 1 : str.length()/2;
    int index = str.length() - 1;
    int length = str.length();

    while (index > i) {
      if (str[index] > str[length - index - 1]) {
        str = increment(index, str);
        i = str.length() % 2 == 0 ? str.length()/2 - 1 : str.length()/2;
        // str[index - 1] = (char)((int)str[index-1] - 47)+48; // +1
        str[index] = str[length - index - 1];
      } else if(str[index] < str[length - index - 1]) {
        str[index] = str[length - index - 1];
      }
      index--;
    }
    if (original.compare(str) == 0) {
      if (i%2 != 0) str[str.length()/2]++;
      else {
        for (int i = 0; i < str.length(); i++) str[i]++;
      }
    }
    cout << str << endl;
  }
  return 0;
}
