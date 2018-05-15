// https://www.codechef.com/problems/PALIN

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkifpallindrome(string str) {
  string rev = str;
  reverse(rev.begin(), rev.end());
  bool val = str.compare(rev) == 0 ? true : false;
  return val;
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

int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    string str;
    cin >> str;
    str = checkifAll9s(str);
    int i = str.length() % 2 == 0 ? str.length()/2 - 1: str.length()/2;
    int index = str.length() - 1;
    int length = str.length();
    while (index > i) {
      if (str[index] > str[length - index - 1]) {
        str[index - 1] = (char)((int)str[index-1] - 47)+48; // +1
        str[index] = str[length - index - 1];
      } else if(str[index] < str[length - index - 1]) str[index] = str[length - index - 1];
      else if(str[index] == str[length - index - 1]) str[index - 1] = (char)((int)str[index-1] - 47)+48; // +1
      index--;
    }
    cout << str << endl;
  }
  return 0;
}
