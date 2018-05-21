// https://www.codechef.com/problems/PALIN

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string input;
    cin >> input;
    int c = 0;
    bool greater = false;
    int i = input.length() / 2 - 1;
    int j = input.length() - (i + 1);

    if (input.length() % 2 == 0) {
      while(i >= 0) {
        if (greater) {
          if (c == 1) {
            if (input[i] == '9') {
              c = 1;
              input[i] = '0';
              input[j] = '0';
            } else {
              input[i]++;
              input[j] = input[i];
              c = 0;
            }
          } else {
            input[j] = input[i];
          }
        } else {
          if (input[i] <= input[j]) {
            if (input[i] == '9') {
              c = 1;
              input[i] = '0';
              input[j] = '0';
            } else {
              c = 0;
              input[i] ++;
            }
          }
          input[j] = input[i];
          greater = true;
        }
        i--;
        j = input.length()- (i + 1);
      }

    } else {
      if (input[input.length()/2] == '9') {
        input[input.length()/2] = '0';
        c = 1;
      } else {
        input[input.length()/2]++;
      }
      while (i >= 0) {
        if (c == 1) {
          if (input[i] == '9') {
            input[i] = '0';
            input[j] = '0';
          } else {
            input[i]++;
            input[j] = input[i];
            c = 0;
          }
        } else {
          input[j] = input[i];
        }
        i--;
        j = input.length() - (i + 1);
      }
    }
    if (c == 1) {
      input.insert(0, "1");
      input[input.length() - 1] = '1';
    }
    cout << input << endl;
  }
  return 0;
}
