// https://www.codechef.com/problems/PALIN
#include <iostream>
#include <string>
using namespace std;

string modify9(string str) {
  int index = str.length() - 1;
  while (str[index] != 9) {
    /* code */
    str[index] = 0;
    if (str[index-1] == 9) {
      /* code */
      str = modify9(str.substr(0, index-1));
      str.push_back(str[index]);
    } else {
      str[index-1] = (char)((int)str[index-1] -47);
    }
    index--;
  }
  return str;
}

string checkall9s(string str) {
  int all9 = true;
  for (int i = 0; i < str.length(); i++) {
    /* code */
    if (str[i] != '9') {
      /* code */
      all9 = false;
    }
  }
  if(all9) {
    for (int i = 0; i < str.length(); i++) str[i] = '0';
    str.insert(0, "1");
  }
  cout << str << endl;
  return str;
}

int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    /* code */
    int n;
    string str;
    cin>>str;
    str = checkall9s(str);

    string sub_first = str.substr(0, str.length()/2);
    sub_first = checkall9s(sub_first);

    int last = (int)sub_first.back() - 48;

    if (str.length() % 2 == 0) {
      /* code */
      string sub_last = str.substr(str.length()/2, str.length());

      int next = (int)sub_last.front() - 48;

      if (last == 9) {
        sub_first = modify9(sub_first);
      }

      if(last <= next) {
        last ++;
        sub_first.pop_back();
        sub_first.push_back((char)last+48);
      }
      int length = sub_first.length();
      for (int i = 0; i < length; i++) {
        sub_first.push_back(sub_first[length-i-1]);
      }
      cout << sub_first << endl;

    } else {
      int mid = (int)str[str.length()/2] - 48;
      string sub_last = str.substr(str.length()/2 + 1, str.length());

      int next = (int)sub_last.front() - 48;

      if(last <= next) {
        if (mid == 9) {
          string sub_mid = str.substr(str.length()/2 + 1);
          sub_mid = modify9(sub_mid);
          mid = (int)sub_mid.back() - 48;
          sub_first = sub_mid.substr(0, sub_mid.length() - 1);
        }
        mid++;
      }

      sub_first.push_back((char)mid+48);
      int length = sub_first.length();
      for (int i = length-2; i >= 0; i--) {
        sub_first.push_back(sub_first[i]);
      }
      cout << sub_first << endl;
    }
  }
  return 0;
}
